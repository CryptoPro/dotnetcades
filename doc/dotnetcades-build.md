Сборка библиотеки для платформы .NET
===
Сборка производится на Ubuntu 23.10.

1. Установить необходимые пакеты для сборки ccades:
```
sudo apt install cmake build-essential libboost-all-dev 
```
2. Скачать [архив с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads), 
(версии 5.0.13000 или выше) распаковать этот архив и установить КриптоПро CSP:
```
tar xvf linux-amd64_deb.tgz
cd linux-amd64_deb
sudo ./install.sh
```
3. Установить пакет cprocsp-devel:
```
sudo apt install ./lsb-cprocsp-devel_5.0*.deb
```
4. Cкачать архив с [КриптоПро ЭЦП SDK](https://cryptopro.ru/products/cades/downloads), 
распаковать этот архив и установить пакет cprocsp-pki-phpcades 
```
tar xvf cades_linux_amd64.tar.gz
cd cades_linux_amd64
sudo apt install ./cprocsp-pki-phpcades*.deb
```
5. Скачать и распаковать архив с исходниками [dotnetcades]():
```
git clone <link>
cd dotnetcades_*
```
6. Выполнить сборку ccades:
```
cd ccades
mkdir build
cd build
cmake ..
make -j4
```
7. Выполнить сборку dotnetcades (и опционально запустить примеры из папки samples)
```
dotnet restore
dotnet build
cd samples
dotnet run
```

