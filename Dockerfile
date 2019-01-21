# Base image
FROM ubuntu:16.04

RUN /bin/bash -c 'echo This woudl generally be apt-get or other system configration'

ENV myCustomerEnvVar="This is a sample." \
    otherEnvVar="This is also a sample."