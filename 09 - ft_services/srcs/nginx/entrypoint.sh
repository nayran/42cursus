#! /bin/sh

telegraf --config /etc/telegraf/telegraf.conf &
/usr/sbin/sshd &
nginx -g 'daemon off;'
