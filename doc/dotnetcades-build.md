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
4. Скачать исходный код [dotnetcades](https://github.com/CryptoPro/dotnetcades):
```
git clone https://github.com/CryptoPro/dotnetcades.git
cd dotnetcades*
```
5. Выполнить сборку ccades:
```
cd ccades
mkdir build
cd build
cmake ..
make -j4
```
6. Выполнить сборку dotnetcades (и опционально запустить примеры из папки samples)
```
dotnet restore
dotnet build
cd samples
dotnet run
```

