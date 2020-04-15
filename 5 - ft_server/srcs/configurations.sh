## instalador de MySQL(MariaDB), NGINX e PHP
apt-get install -y openssl mariadb-server nginx php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline php-json php-mbstring php7.3-mbstring php-curl php-gd php-intl php-soap php-xml php-xmlrpc php-zip

# diretorio
mkdir /var/www/localhost
cd /root/

# PHP
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.1/phpMyAdmin-4.9.1-english.tar.gz
tar -xf phpMyAdmin-4.9.1-english.tar.gz && rm -rf phpMyAdmin-4.9.1-english.tar.gz
mv phpMyAdmin-4.9.1-english /var/www/localhost/phpmyadmin
cp -pr ./config.inc.php /var/www/localhost/phpmyadmin/config.inc.php
cp -pr ./nginx.conf /etc/nginx/sites-available/default
chown -R www-data:www-data /var/www/localhost/phpmyadmin

# SSL (cuidar localizacao)
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj '/C=BR/ST=SP/L=SP/O=42/CN=nasimon' 		\
	-keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

## cria DB e acesso root
echo "CREATE DATABASE wpbase DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
mysqladmin --user=root password "nasimon"

## WordPress
wget https://br.wordpress.org/wordpress-5.3.2-pt_BR.tar.gz
tar -xf wordpress-5.3.2-pt_BR.tar.gz && rm -rf wordpress-5.3.2-pt_BR.tar.gz
cp wp-config.php wordpress/wp-config.php
mv wordpress /var/www/localhost/
