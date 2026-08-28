# cp -r ~/csp/ .
# make docker

FROM mcr.microsoft.com/dotnet/sdk:10.0

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y git \
    cmake \
    build-essential \
    libboost-all-dev \
    lsb-release \
    ca-certificates && \
    rm -rf /var/lib/apt/lists/*

RUN update-ca-certificates

COPY csp csp

RUN ./csp/install.sh kc1 \
    lsb-cprocsp-devel \
    cprocsp-legacy \
    cprocsp-pki-cades

COPY . /dotnetcades/

WORKDIR /dotnetcades

RUN (SCRIPTS_DIR=./tests/scripts && \
    chmod +x ${SCRIPTS_DIR}/*.sh && \
    ${SCRIPTS_DIR}/setup-root.sh && \
    ${SCRIPTS_DIR}/setup-leaf.sh && \
    ${SCRIPTS_DIR}/setup-crl.sh) > /dev/null 2>&1

RUN make
