FROM debian:buster
MAINTAINER nasimon- <nasimon-@student.42sp.org.br>
COPY srcs /root/ 

## nao trava instalacao
ARG DEBIAN_FRONTEND=noninteractive

## remove erros
RUN printf "#!/bin/sh\nexit 0" > /usr/sbin/policy-rc.d

## utilitarios
RUN bash /root/utils.sh

ENTRYPOINT bash /root/entrypoint.sh

CMD tail -f /dev/null
