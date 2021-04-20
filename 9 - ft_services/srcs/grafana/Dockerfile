FROM alpine:3.12

RUN apk -U upgrade && \
	apk add openrc tar wget bash vim && \
	apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted && \
	apk add --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat && \
	mkdir -p /usr/share/ && \
	mkdir -p /etc/telegraf/

COPY ./grafana/grafana /usr/share/grafana
COPY ./grafana/grafana.db /usr/share/grafana/data/grafana.db
COPY ./influxdb/telegraf.conf /etc/telegraf/telegraf.conf
RUN sed -i "s/SVC-NAME/grafana/g" /etc/telegraf/telegraf.conf

EXPOSE 3000

ENTRYPOINT  (telegraf --config /etc/telegraf/telegraf.conf &) && /usr/share/grafana/bin/grafana-server --homepath=/usr/share/grafana
