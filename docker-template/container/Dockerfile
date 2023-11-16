# syntax=docker/dockerfile:1

# Get base image
FROM debian:12.2-slim

# Create a non-root user, and assign it owner privileges to /home/user/project
RUN set -ex; \
  addgroup --gid 1000 "group"; \
  adduser \
    --home "/home/user" \
    --gecos "OCI default user" \
    --shell "/bin/bash" \
    --uid 1000 \
    --gid 1000 \
    --disabled-password \
    "user"; \
  mkdir -p /home/user/project; \
  chown user:group /home/user/project

# Install packages, this is expected to change quite often
RUN set -ex; \
  apt-get update; \
  apt-get install --no-install-recommends --yes \
    binutils \
    ca-certificates \
    cmake \
    git \
    make \
    ninja-build \
    openssh-client \
    gdb \
    gcc \
    g++ \
  ; \
  apt-get remove --purge --auto-remove --yes; \
  rm -rf /var/lib/apt/lists/*

# EOF
