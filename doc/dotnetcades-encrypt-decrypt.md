Шифрование и расшифрование данных
===

Пример шифрования и расшифрования данных.

```csharp
using System;
using dotnetcades;

namespace samples
{
    class EncryptDecrypt
    {
        public static void run()
        {
            const string CertificateSN = "Test Certificate";
            const string DataToSign = "Test content to be signed";
            try
            {
                using var oStore = new dotnetcades.Store();
                oStore.Open(NC.CADESCOM_CURRENT_USER_STORE, NC.CAPICOM_MY_STORE, NC.CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED);

                using var oCertificates = oStore.Certificates;
                using var foundCerts = oCertificates.Find(NC.CAPICOM_CERTIFICATE_FIND_SUBJECT_NAME, CertificateSN);
                if (foundCerts.Count == 0)
                {
                    Console.WriteLine($"Certificates with private key not found");
                    return;
                }

                using var oCertificate = foundCerts.Item(1);
                using var oEnvelopedData = new dotnetcades.EnvelopedData();
                oEnvelopedData.Content = DataToSign;
                using var oRecipients = oEnvelopedData.Recipients;
                oRecipients.Add(oCertificate);
                var encryptedMessage = oEnvelopedData.Encrypt();
                Console.WriteLine($"Encrypted Message: {encryptedMessage}");

                var oEnvelopedDataDecrypt = new dotnetcades.EnvelopedData();
                oEnvelopedDataDecrypt.Decrypt(encryptedMessage);
                Console.WriteLine($"Decrypted successfully");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
```