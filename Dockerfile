FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    vim \
    git \
    zsh \
    valgrind \  
    && apt-get clean

WORKDIR /project