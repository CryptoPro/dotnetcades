Пример использования dotnetcades
===
Для работы примеров необходим сертификат с привязкой к закрытому ключу.

Тестовый сертификат можно установить с помощью команды (для amd64):
```bash
/opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=Test Certificate" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
```

В данном разделе
---

[Пример создания и проверки подписи](/cades/dotnetcades/dotnetcades-samples/dotnetcades-sign-verify.md)<br>
[Пример создания и проверки отделенной подписи формата CAdES-BES по хэш-значению данных](/cades/dotnetcades/dotnetcades-samples/dotnetcades-signhash-verifyhash.md)<br>
[Пример создания и проверки подписи документа XML](/cades/dotnetcades/dotnetcades-samples/dotnetcades-sign-verify-xml.md)<br>
[Пример шифрования и расшифрования данных](/cades/dotnetcades/dotnetcades-samples/dotnetcades-encrypt-decrypt.md)<br>

