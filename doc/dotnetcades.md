Библиотека dotnetcades для .NET
===
dotnetcades представляет собой библиотеку для .NET. Библиотека реализует интерфейс, аналогичный [CAdESCOM](https://docs.cryptopro.ru/cades/reference/cadescom).
Библиотека предназначена для встраивания криптографических операций в серверные приложения для платформы .NET с использованием сертифицированного СКЗИ КриптоПро CSP.

Библиотека предоставляет программный интерфейс, аналогичный КриптоПро ЭЦП Browser plug-in, для выполнения следующих криптографических операций:
* работа с сертификатами;
* создание и проверка подписи форматов CAdES BES, CAdES-T, CAdES-X Long Type 1;
* шифрование и расшифрование данных.

### Особенности
В библотеке dotnetcades добавлены все константы из списка [свойств плагина](https://docs.cryptopro.ru/cades/plugin/plugin-methods?id=%d0%9a%d0%be%d0%bd%d1%81%d1%82%d0%b0%d0%bd%d1%82%d1%8b). 

Для создания объектов необходимо вызвать соответствующий конструктор. Для создания доступны следующие объекты:

|Объект CAdESCOM|Объект dotnetcades|
|-|-|
|[CAdESCOM.About](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/about)|dotnetcades.About|
|[CAdESCOM.CadesSignedData](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cadessigneddata)|dotnetcades.SignedData|
|[CAdESCOM.CPAttribute](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cpattribute)|dotnetcades.Attribute|
|[CAdESCOM.Certificate](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cpcertificate)|dotnetcades.Certificate|
|[CAdESCOM.CRL](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cpcrl)|dotnetcades.CRL|
|[CAdESCOM.CPEnvelopedData](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cpenvelopeddata)|dotnetcades.EnvelopedData|
|[CAdESCOM.HashedData](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cphasheddata)|dotnetcades.HashedData|
|[CAdESCOM.CPSigner](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/cpsigner)|dotnetcades.Signer|
|[CAdESCOM.RawSignature](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/rawsignature)|dotnetcades.RawSignature|
|[CAdESCOM.SignedXML](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/signedxml)|dotnetcades.SignedXML|
|[CAdESCOM.Store](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/store)|dotnetcades.Store|
|[CAdESCOM.SymmetricAlgorithm](https://docs.cryptopro.ru/cades/reference/cadescom/cadescom_class/symmetricalgorithm)|dotnetcades.SymmetricAlgorithm|

Лицензирование
---
Библиотека распространяется бесплатно в виде исходных кодов и для своего функционирования не требует отдельной лицензии.
Для формирования ЭЦП с использованием криптоалгоритма ГОСТ необходима лицензия на КриптоПро CSP. 
Для формирования усовершенствованной ЭЦП необходимы лицензии на КриптоПро TSP Client и КриптоПро OCSP Client.

В этом разделе
---
[Сборка библиотеки для языка .NET](/cades/dotnetcades/dotnetcades-build.md)<br/>
[Пример использования](/cades/dotnetcades/dotnetcades-samples.md)<br/>
