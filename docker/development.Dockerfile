From ubuntu:22.04

RUN apt update && \
    apt install -y cmake build-essential vim nano git clang-format-11 
