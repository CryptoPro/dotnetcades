Сборка библиотеки для платформы .NET
===


## Dockerfile

В качестве примера сборки в репозитории представлен [Dockerfile](../Dockerfile).

Для построения образа и проверки работы библиотеки необходимо: 
1. В директории с Dockerfile поместить папку с пакетами из [архива с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads):
    ```bash
    cp -r ~/linux-amd64_deb/ .
    ```
1. Собрать образ:
    ```bash
    docker build -t dotnetcades-build .
    ```
1. Запустить контейнер с собранным образом:
    ```
    docker run -it -w /dotnetcades/samples/ dotnetcades-build
    ```
1. Сгенерировать тестовый сертификат с привязкой к закрытому ключу:
    ```
    /opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=test" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
    ```
1. Выполнить пример:
    ```
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/dotnetcades/src/ccades && dotnet run
    ```


## Ubuntu

Сборка производится на Ubuntu 24.04 + КриптоПро CSP 5.0.13000 + .NET 3.1

1. Установить необходимые пакеты для сборки:
    ```
    sudo apt install cmake build-essential libboost-all-dev 
    ```
1. Скачать [архив с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads), 
распаковать этот архив и установить КриптоПро CSP, а также пакеты lsb-cprocsp-devel, cprocsp-pki-cades, cprocsp-legacy:
    ```
    tar xvf linux-amd64_deb.tgz
    cd linux-amd64_deb
    sudo ./install.sh lsb-cprocsp-devel cprocsp-legacy cprocsp-pki-cades
    ```
1. Скачать исходный код dotnetcades
    ```
    git clone https://github.com/CryptoPro/dotnetcades.git
    cd dotnetcades/src
    ```
1. Выполнить сборку ccades:
    ```
    cd ccades
    mkdir build
    cd build
    cmake ..
    make -j4
    ```
1. Обеспечить доступность собранной библиотеки libccades.so для dlopen ([подробнее](https://www.mono-project.com/docs/advanced/pinvoke/#linux-shared-library-search-path)).<br/> Например, добавить путь до libccades.so в переменную окружения LD_LIBRARY_PATH:
    ```
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/libccades_folder
    ```
1. Выполнить сборку dotnetcades (и опционально запустить примеры из папки samples)
    ```
    dotnet restore
    dotnet build
    cd samples
    dotnet run
    ```