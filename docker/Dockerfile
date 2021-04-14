FROM debian:stretch
LABEL maintainer="But Developers <dev@but.xyz>"
LABEL description="Dockerised ButCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
