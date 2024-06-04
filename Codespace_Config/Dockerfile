FROM ubuntu:latest

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Install essential development tools
RUN apt-get update && apt-get install -y \
    sudo \
    build-essential \
    cmake \
    gdb \
    git \
    wget \
    curl \
    vim \
    nano \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user and give them sudo access
RUN useradd -ms /bin/bash vscode \
    && echo 'vscode ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# Switch to the non-root user
USER vscode

# Set up workspace directory
RUN mkdir -p /workspace
WORKDIR /workspace
