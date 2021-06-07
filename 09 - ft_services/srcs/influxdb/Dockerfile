FROM alpine:3.12

RUN apk -U upgrade && \
	apk add influxdb bash vim && \
	apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted && \
	mkdir -p /etc/telegraf/

COPY ./influxdb/telegraf.conf /etc/telegraf/telegraf.conf
RUN sed -i "s/SVC-NAME/influxdb/g" /etc/telegraf/telegraf.conf

EXPOSE 8086

ENTRYPOINT (telegraf --config /etc/telegraf/telegraf.conf &) && influxd run -config /etc/influxdb.conf
