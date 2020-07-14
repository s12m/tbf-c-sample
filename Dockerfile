FROM debian:buster-slim
LABEL maintainer "Smart Algorithm Co., Ltd. <contact@smartalgorithm.co.jp>"

RUN apt-get update && \
    apt-get install -y --no-install-recommends libc6-dev gcc make valgrind

WORKDIR /work
