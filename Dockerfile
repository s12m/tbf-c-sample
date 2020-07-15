FROM debian:buster-slim
LABEL maintainer "Smart Algorithm Co., Ltd. <contact@smartalgorithm.co.jp>"

ENV LANG C.UTF-8
RUN apt-get update && \
    apt-get install -y --no-install-recommends libc6-dev gcc make valgrind

WORKDIR /work
