# cp -r ~/csp/ .
# docker build -t dotnetcades-build .

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

RUN make

# docker run -it dotnetcades-build
# /opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=Test Certificate" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/dotnetcades/src/ccades && cd samples && dotnet run
