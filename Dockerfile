# Base image
FROM ubuntu:16.04

RUN /bin/bash -c 'echo This woudl generally be apt-get or other system configration'

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    build-essential \
    wget \
    libopencv-dev

WORKDIR /opt
RUN wget http://www.cmake.org/files/v3.12/cmake-3.12.1.tar.gz && \
        tar -xvzf cmake-3.12.1.tar.gz && \
        cd cmake-3.12.1/ && \
        ./configure  && \
        make -j8 && \
        make install

ENV myCustomerEnvVar="This is a sample." \
    otherEnvVar="This is also a sample."