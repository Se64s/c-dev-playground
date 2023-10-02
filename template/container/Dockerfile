# syntax=docker/dockerfile:1

# Get base image
FROM alpine:3.18

# Get utils
RUN apk update && apk add --no-cache build-base cmake ninja gdb

# Define user
ARG user=dev
ARG home=/home/$user
RUN addgroup -S docker
RUN adduser \
    --disabled-password \
    --gecos "" \
    --home $home \
    --ingroup docker \
    $user

# Setup workdir
WORKDIR $home
