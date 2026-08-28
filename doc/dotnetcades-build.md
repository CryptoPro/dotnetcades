Сборка библиотеки для платформы .NET
===


## Dockerfile

В качестве примера сборки в репозитории представлен [Dockerfile](../Dockerfile).

Для построения образа и проверки работы библиотеки необходимо: 
1. В директории с Dockerfile поместить папку с пакетами из [архива с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads):
    ```bash
    cp -r ~/csp/ .
    ```
1. Собрать образ:
    ```bash
    make docker-build
    ```
1. Выполнить пример в контейнере с тестовыми сертификатами:
    ```
    make docker
    ```


## Ubuntu

Сборка производится на Ubuntu 24.04 (amd64) + КриптоПро CSP 5.0.13000 + .NET 10.0

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
    cd dotnetcades
    ```
1. Выполнить сборку ccades и dotnetcades:
    ```
    make build
    ```
1. Обеспечить доступность собранной библиотеки libccades.so для dlopen ([подробнее](https://www.mono-project.com/docs/advanced/pinvoke/#linux-shared-library-search-path)).<br/> Например, добавить путь до libccades.so в переменную окружения LD_LIBRARY_PATH:
    ```
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/libccades_folder
    ```
1. Запустить примеры из папки samples
    ```
    make run-samples
    ```