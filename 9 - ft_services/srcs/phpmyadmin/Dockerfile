FROM alpine:3.12

RUN apk -U upgrade && \
	apk add --update bash nginx wget tar openssl php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session && \
	apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted && \
	adduser -D -g www www && \
	mkdir /www && \
	chown -R www:www /var/lib/nginx && \
	chown -R www:www /www && \
	mkdir -p /run/nginx && \
	rm /etc/nginx/nginx.conf && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/selfsigned.key -out /etc/ssl/certs/selfsigned.crt -subj "/C=BR/ST=SP/L=SP/O=SP/OU=SP/CN=nasimon-" && \
	mkdir -p /var/www && \
	rm -f /etc/nginx/nginx.conf && \
	mkdir -p /usr/share/webapps/ ; \
	cd /usr/share/webapps ; \
	wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.4-all-languages.tar.gz ; \
	tar -xzvf phpMyAdmin-5.0.4-all-languages.tar.gz ; \
	rm phpMyAdmin-5.0.4-all-languages.tar.gz ; \
	mv phpMyAdmin-5.0.4-all-languages phpmyadmin ; \
	chmod -R 777 /usr/share/webapps/ ; \
	ln -s /usr/share/webapps/phpmyadmin/ /var/www/localhost/htdocs/phpmyadmin ; \
	rm -rf /usr/share/nginx/html && \
	mkdir /etc/telegraf/

COPY ./phpmyadmin/default.conf /etc/nginx/conf.d/default.conf
COPY ./phpmyadmin/default.conf /etc/nginx/nginx.conf
COPY ./phpmyadmin/config.inc.php /usr/share/webapps/phpmyadmin/
COPY ./influxdb/telegraf.conf /etc/telegraf/telegraf.conf
RUN sed -i "s/SVC-NAME/phpmyadmin/g" /etc/telegraf/telegraf.conf

EXPOSE	5000

CMD (telegraf --config /etc/telegraf/telegraf.conf &) && php-fpm7 && nginx -g 'daemon off;'
