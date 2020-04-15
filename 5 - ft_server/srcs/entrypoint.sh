/etc/init.d/mysql start
/etc/init.d/nginx start
/etc/init.d/php7.3-fpm start

tail -f /var/log/nginx/access.log /var/log/nginx/error.log
