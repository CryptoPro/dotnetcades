using System;
using dotnetcades;

namespace samples
{
    class SignVerifyCadesBes
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

                using var oSigner = new dotnetcades.Signer();
                using var oCertificate = foundCerts.Item(1);
                oSigner.Certificate = oCertificate;
                oSigner.CheckCertificate = true;

                using var oSignedData = new dotnetcades.SignedData();
                oSignedData.Content = DataToSign;
                var signature = oSignedData.SignCades(oSigner, NC.CADESCOM_CADES_BES);
                Console.WriteLine($"Signed Message: {signature}");

                var oSignedDataVerify = new dotnetcades.SignedData();
                oSignedDataVerify.VerifyCades(signature, NC.CADESCOM_CADES_BES);
                Console.WriteLine($"Verified successfully");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
