FROM alpine:3.12

RUN apk -U upgrade && \
    apk add bash nginx openssh openssl &&\
    apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted && \
    adduser -D -g www www && \
    mkdir -p /etc/telegraf/ && \
    mkdir /www && \
    chown -R www:www /var/lib/nginx && \
    chown -R www:www /www && \
    adduser -D admin && \
    echo "admin:password" | chpasswd && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=BR/ST=SP/L=SP/O=SP/OU=SP/CN=nasimon-" && \
    ssh-keygen -A && \
    rm -f /etc/nginx/nginx.conf && rm -f /var/lib/nginx/html/index.hml

COPY ./nginx/entrypoint.sh ./entrypoint.sh
RUN chmod 777 ./entrypoint.sh
COPY ./nginx/nginx2.conf /etc/nginx/nginx.conf
COPY ./nginx/index.html /var/lib/nginx/html/index.html
COPY ./influxdb/telegraf.conf /etc/telegraf/telegraf.conf
RUN sed -i "s/SVC-NAME/nginx/g" /etc/telegraf/telegraf.conf

EXPOSE 22 80 443

ENTRYPOINT ./entrypoint.sh
