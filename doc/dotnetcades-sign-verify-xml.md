Создание и проверка подписи документа XML
===

Пример создания и проверки подписи документа XML.

```csharp
using System;
using dotnetcades;

namespace samples
{
    class SignVerifyXML
    {
        public static void run()
        {
            const string CertificateSN = "Test Certificate";
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

                using var oSigner = new dotnetcades.Signer();
                using var oCertificate = foundCerts.Item(1);
                oSigner.Certificate = oCertificate;
                oSigner.CheckCertificate = true;

                var ContentToSign = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
                ContentToSign += "<!-- ";
                ContentToSign += "XML Security Library example: Original XML doc file for sign2 example. ";
                ContentToSign += "-->";
                ContentToSign += "<Envelope xmlns=\"urn:envelope\">";
                ContentToSign += "  <Data>";
                ContentToSign += "    Hello, World!";
                ContentToSign += "  </Data>";
                ContentToSign += "  <Node xml:id=\"nodeID\">";
                ContentToSign += "    Hello, Node!";
                ContentToSign += "  </Node>" + " " + "</Envelope>";
                using var oSignedXML = new dotnetcades.SignedXML();
                oSignedXML.Content = ContentToSign;
                oSignedXML.SignatureType = NC.CADESCOM_XML_SIGNATURE_TYPE_ENVELOPED | NC.CADESCOM_XADES_BES;
                var signature = oSignedXML.Sign(oSigner);
                Console.WriteLine($"Signed Message: {signature}");

                using var oSignedXMLVerify = new dotnetcades.SignedXML();
                oSignedXMLVerify.Verify(signature);
                Console.WriteLine($"Verified successfully");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
```