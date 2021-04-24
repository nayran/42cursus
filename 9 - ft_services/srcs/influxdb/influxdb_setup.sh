#!/bin/bash

influxd run -config /etc/influxdb.conf &
telegraf --config /etc/telegraf/telegraf.conf &
tail -f /dev/null /dev/null
