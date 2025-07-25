Сборка библиотеки для платформы .NET
===
Сборка производится на Ubuntu 23.10.

1. Установить необходимые пакеты для сборки ccades:
```
sudo apt install cmake build-essential libboost-all-dev 
```
2. Скачать [архив с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads), 
(версии 5.0.13000 или выше) распаковать этот архив и установить КриптоПро CSP, а также пакеты lsb-cprocsp-devel и cprocsp-pki-cades::
```
tar xvf linux-amd64_deb.tgz
cd linux-amd64_deb
sudo ./install.sh lsb-cprocsp-devel cprocsp-pki-cades
```
3. Скачать исходный код [dotnetcades](https://github.com/CryptoPro/dotnetcades):
```
git clone https://github.com/CryptoPro/dotnetcades.git
cd dotnetcades*
```
4. Выполнить сборку ccades:
```
cd ccades
mkdir build
cd build
cmake ..
make -j4
```
5. Обеспечить доступность собранной библиотеки libccades.so для dlopen ([подробнее](https://www.mono-project.com/docs/advanced/pinvoke/#linux-shared-library-search-path)).<br/>
Например, добавить путь до libccades.so в переменную окружения LD_LIBRARY_PATH:
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/libccades_folder
```
6. Выполнить сборку dotnetcades (и опционально запустить примеры из папки samples)
```
dotnet restore
dotnet build
cd samples
dotnet run
```

