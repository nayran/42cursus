		### FT_SERVER ###
	
- Rodar Dockerfile // montar imagem
docker build . -t (nome)

- Rodar container
docker run -p 80:80 (nome)

- Mostrar imagens
docker images

- Mostrar containers
docker ps -a

- Remover imagens
docker image rm (image_id)

- Remover container
docker container rm (container_id)

- Todos os logins
login: root
senha: nasimon
