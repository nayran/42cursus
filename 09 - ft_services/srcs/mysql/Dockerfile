FROM alpine:3.12

COPY ./mysql/mysql_setup.sh /mysql_setup.sh

RUN apk -U upgrade && \
	apk add openrc bash vim mysql mysql-client && \
	rm -f /var/cache/apk/* && \
	apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted && \
	mkdir /etc/telegraf/ && \
	rm -f /etc/my.cnf.d/mariadb-server.cnf && \
	chmod +x /mysql_setup.sh

COPY ./influxdb/telegraf.conf /etc/telegraf/telegraf.conf
RUN sed -i "s/SVC-NAME/mysql/g" /etc/telegraf/telegraf.conf
 
COPY ./mysql/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

EXPOSE 3306

ENTRYPOINT bash mysql_setup.sh
