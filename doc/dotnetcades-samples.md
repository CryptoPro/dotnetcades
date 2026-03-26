Пример использования dotnetcades
===
Для работы примеров необходим сертификат с привязкой к закрытому ключу.

Тестовый сертификат можно установить с помощью команды (для amd64):
```bash
/opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=Test Certificate" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
```

В данном разделе
---

[Пример создания и проверки подписи](../samples/SignVerifyCadesBes.cs)<br>
[Пример создания и проверки отделенной подписи формата CAdES-BES по хэш-значению данных](../samples/SignHashVerifyHash.cs)<br>
[Пример создания и проверки подписи документа XML](../samples/SignVerifyXML.cs)<br>
[Пример шифрования и расшифрования данных](../samples/EncryptDecrypt.cs)<br>

