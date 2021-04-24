FROM alpine:3.12

ARG IP
ENV IP=$IP

RUN apk -U upgrade && \
	apk add bash openssl && \
    apk add pure-ftpd --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted && \
    apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted

RUN adduser -D -g admin admin && \
    echo "admin:password" | chpasswd &&\
	mkdir -p /etc/telegraf/ && \
    mkdir -p /etc/ssl/private &&\
	chmod 777 /etc/ssl/private &&\
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/pure-ftpd.pem -out /etc/ssl/private/pure-ftpd.pem -subj "/C=BR/ST=SP/L=SP/O=SP/OU=SP/CN=nasimon-" && \
    chmod 600 /etc/ssl/private/pure-ftpd.pem

COPY ./influxdb/telegraf.conf /etc/telegraf/telegraf.conf
RUN sed -i "s/SVC-NAME/ftps/g" /etc/telegraf/telegraf.conf

EXPOSE 21 30020

ENTRYPOINT (telegraf --config /etc/telegraf/telegraf.conf &) && /usr/sbin/pure-ftpd -p 30020:30020 -P $IP
