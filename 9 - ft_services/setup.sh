#! /bin/bash

function ft_run ()
{
	eval $(minikube docker-env)
	IP=$(minikube ip)

	echo "Enabling Addons"
	minikube addons enable dashboard 
	minikube addons enable ingress 
	minikube addons enable metrics-server 
	minikube addons enable storage-provisioner 
	
	
	echo "MetalLB"
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml 
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml 
	kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" 
	kubectl apply -f ./srcs/metallb/metallb.yaml 
#	minikube addons enable metallb 

	echo "InfluxDB"
	docker build -t influxdb -f ./srcs/influxdb/Dockerfile ./srcs/ 
	kubectl create -f srcs/influxdb/influxdb.yaml 
	
	echo "MySQL"
	docker build -t mysql -f ./srcs/mysql/Dockerfile ./srcs/ --build-arg IP=${IP} 
	kubectl create -f srcs/mysql/mysql.yaml 

	echo "FTPS"
	docker build -t ftps -f ./srcs/ftps/Dockerfile ./srcs/ --build-arg IP=192.168.99.234 
	kubectl create -f srcs/ftps/ftps.yaml 
	
	echo "WordPress"
	docker build -t wordpress -f  ./srcs/wordpress/Dockerfile ./srcs/ --build-arg IP=192.168.99.235 
	kubectl create -f srcs/wordpress/wordpress.yaml 

	echo "phpMyAdmin"
	docker build -t phpmyadmin -f ./srcs/phpmyadmin/Dockerfile ./srcs/ 
	kubectl create -f srcs/phpmyadmin/phpmyadmin.yaml 

	echo "Nginx"
	docker build -t nginx -f ./srcs/nginx/Dockerfile ./srcs/ 
	kubectl create -f srcs/nginx/nginx.yaml 

	echo "Grafana"
	docker build -t grafana -f ./srcs/grafana/Dockerfile ./srcs/ 
	kubectl create -f srcs/grafana/grafana.yaml 
	
	clear
	echo "Service list"
	kubectl get services -o wide
	
	echo "Launching Dashboard"
	minikube dashboard &
}


function ft_macinstall ()
{
	echo "Installing packages"
	/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" 
	brew install docker 
	brew install minikube 
	echo "OK"
	clear
}

function ft_linuxinstall ()
{
	echo "Installing packages"
	sudo apt-get update -y 
	sudo apt-get install -y apt-transport-https ca-certificates curl gnupg 
	curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg 
	sudo apt-get install -y docker docker-ce docker-ce-cli containerd.io 
	curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64 
	sudo install minikube-linux-amd64 /usr/local/bin/minikube 
	sudo groupadd docker 
	sudo usermod -aG docker ${USER} 
	su ${USER} 
	cat srcs/config > ~/.kube/config
	echo "OK"
	clear
}

function ft_clean ()
{
	clear
	echo "Cleaning"
	docker system prune --force 
	minikube delete --all --purge
	minikube delete 
}

OS=$(eval uname)
if [ "$OS" = "Linux" ]
then
	echo "Running on Linux"
	#ft_linuxinstall
	sudo chmod 666 /var/run/docker.sock 
	ft_clean
	echo "Starting minikube"
	minikube start --driver=docker --extra-config=apiserver.service-node-port-range=20-35000 
	ft_run
else
	echo "Running on Mac"
	ft_clean
	ft_macinstall
	echo "Starting minikube"
	minikube start --driver=virtualbox --extra-config=apiserver.service-node-port-range=20-35000 
	ft_run
fi

