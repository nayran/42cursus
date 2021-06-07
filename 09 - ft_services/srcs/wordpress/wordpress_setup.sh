#!/bin/bash
mkdir /run/openrc
touch /run/openrc/softlevel
openrc

wp plugin deactivate –all

wp core install \
        --url=https://MINIKUBE-IP:5050 \
        --title="wordpress" \
        --admin_user=admin \
        --admin_password=password \
        --admin_email=admin@admin.com \
		--path='/usr/share/webapps/wordpress/' \
		--skip-email

while [ $? -ne 0 ] ; do
    wp core install \
        --url=https://MINIKUBE-IP:5050 \
        --title="wordpress" \
        --admin_user=admin \
        --admin_password=password \
        --admin_email=admin@admin.com \
		--path='/usr/share/webapps/wordpress/' \
		--skip-email
done

wp user create user1 user1@users.com \
		--first_name=User --last_name=One \
		--role=subscriber \
		--user_pass=user1 \
		--allow-root --path='/usr/share/webapps/wordpress/'

wp user create user2 user2@users.com \
		--first_name=User --last_name=Two \
		--role=editor \
		--user_pass=user2 \
		--allow-root --path='/usr/share/webapps/wordpress/'

wp user create user3 user3@users.com \
		--first_name=User --last_name=Three \
		--role=author \
		--user_pass=user3 \
		--allow-root --path='/usr/share/webapps/wordpress/'


(telegraf --config /etc/telegraf/telegraf.conf &) && php-fpm7 && nginx -g 'daemon off;'
