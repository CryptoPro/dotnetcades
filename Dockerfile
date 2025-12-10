# cp -r ~/linux-amd64_deb/ .
# docker build -t dotnetcades-build .

FROM mcr.microsoft.com/dotnet/core/sdk:3.1

ENV DEBIAN_FRONTEND=noninteractive

RUN sed -i 's|http://deb.debian.org/debian|http://archive.debian.org/debian|g' /etc/apt/sources.list && \
    sed -i 's|http://security.debian.org/debian-security|http://archive.debian.org/debian-security|g' /etc/apt/sources.list && \
    apt-get update && \
    apt-get install -y git \
        cmake \
        build-essential \
        libboost-all-dev \
        lsb-release \
        ca-certificates

RUN update-ca-certificates

COPY linux-amd64_deb csp

RUN ./csp/install.sh

RUN apt-get install -y --no-install-recommends \
        ./csp/cprocsp-rdr-gui-gtk* \
        ./csp/lsb-cprocsp-devel* \
        ./csp/cprocsp-pki-cades* && \
    rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/CryptoPro/dotnetcades.git

WORKDIR /dotnetcades

RUN cd ccades && mkdir build && cd build && \
    cmake .. && make -j$(nproc)

RUN dotnet restore && dotnet build

# docker run -it dotnetcades-build
# /opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=Test Certificate" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/dotnetcades/ccades && cd samples && dotnet run
