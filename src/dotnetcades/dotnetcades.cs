using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public static class NC
    {
        [DllImport("libccades")]
        public static extern int FreeString(IntPtr szString);

        [DllImport("libccades")]
        public static extern IntPtr CSGetErrorMessage(int hresult);

        public static string GetErrorMessage(int hresult)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                ptr = CSGetErrorMessage(hresult);
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                FreeString(ptr);
            }
        }
        public const int CADESCOM_STRING_TO_UCS2LE = 0;
        public const int CADESCOM_BASE64_TO_BINARY = 1;
        public const int CAPICOM_LOCAL_MACHINE_STORE = 1;
        public const int CAPICOM_CURRENT_USER_STORE = 2;
        public const int CADESCOM_MEMORY_STORE = 0;
        public const int CADESCOM_LOCAL_MACHINE_STORE = 1;
        public const int CADESCOM_CURRENT_USER_STORE = 2;
        public const int CADESCOM_CONTAINER_STORE = 100;
        public const int CAPICOM_STORE_OPEN_READ_ONLY = 0;
        public const int CAPICOM_STORE_OPEN_READ_WRITE = 1;
        public const int CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED = 2;
        public const int CADESCOM_XML_SIGNATURE_TYPE_ENVELOPED = 0;
        public const int CADESCOM_XML_SIGNATURE_TYPE_ENVELOPING = 1;
        public const int CADESCOM_XML_SIGNATURE_TYPE_TEMPLATE = 2;
        public const int CADESCOM_CADES_DEFAULT = 0;
        public const int CADESCOM_CADES_BES = 1;
        public const int CADESCOM_CADES_T = 0x5;
        public const int CADESCOM_CADES_X_LONG_TYPE_1 = 0x5d;
        public const int CADESCOM_CADES_A = 0xdd;
        public const int CADESCOM_PKCS7_TYPE = 0xffff;
        public const int CADESCOM_ENCODE_BASE64 = 0;
        public const int CADESCOM_ENCODE_BINARY = 1;
        public const int CADESCOM_XADES_DEFAULT = 0x00000010;
        public const int CADESCOM_XADES_BES = 0x00000020;
        public const int CADESCOM_XADES_T = 0x00000050;
        public const int CADESCOM_XADES_X_LONG_TYPE_1 = 0x000005d0;
        public const int CADESCOM_XADES_A = 0x000007d0;
        public const int CADESCOM_XMLDSIG_TYPE = 0;
        public const int CAPICOM_CERTIFICATE_INCLUDE_WHOLE_CHAIN = 1;
        public const int CAPICOM_CERTIFICATE_INCLUDE_END_ENTITY_ONLY = 2;
        public const int CAPICOM_CERTIFICATE_INCLUDE_CHAIN_EXCEPT_ROOT = 0;
        public const int CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME = 0;
        public const int CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME = 1;
        public const int CAPICOM_CERTIFICATE_FIND_SHA1_HASH = 0;
        public const int CAPICOM_CERTIFICATE_FIND_SUBJECT_NAME = 1;
        public const int CAPICOM_CERTIFICATE_FIND_ISSUER_NAME = 2;
        public const int CAPICOM_CERTIFICATE_FIND_ROOT_NAME = 3;
        public const int CAPICOM_CERTIFICATE_FIND_TEMPLATE_NAME = 4;
        public const int CAPICOM_CERTIFICATE_FIND_EXTENSION = 5;
        public const int CAPICOM_CERTIFICATE_FIND_EXTENDED_PROPERTY = 6;
        public const int CAPICOM_CERTIFICATE_FIND_APPLICATION_POLICY = 7;
        public const int CAPICOM_CERTIFICATE_FIND_CERTIFICATE_POLICY = 8;
        public const int CAPICOM_CERTIFICATE_FIND_TIME_VALID = 9;
        public const int CAPICOM_CERTIFICATE_FIND_TIME_NOT_YET_VALID = 10;
        public const int CAPICOM_CERTIFICATE_FIND_TIME_EXPIRED = 11;
        public const int CAPICOM_CERTIFICATE_FIND_KEY_USAGE = 12;
        public const int CAPICOM_DIGITAL_SIGNATURE_KEY_USAGE = 128;
        public const int CAPICOM_PROPID_ENHKEY_USAGE = 9;
        public const int CAPICOM_OID_OTHER = 0;
        public const int CAPICOM_OID_KEY_USAGE_EXTENSION = 10;
        public const int CAPICOM_ENCODE_BINARY = 1;
        public const int CAPICOM_ENCODE_ANY = unchecked((int)0xffffffff);
        public const int CAPICOM_EKU_OTHER = 0;
        public const int CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME = 0;
        public const int CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME = 1;
        public const int CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION = 2;
        public const int CADESCOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME = 0;
        public const int CADESCOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME = 1;
        public const int CADESCOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION = 2;
        public const int CADESCOM_ATTRIBUTE_OTHER = -1;
        public const int CADESCOM_DISPLAY_DATA_NONE = 0;
        public const int CADESCOM_DISPLAY_DATA_CONTENT = 1;
        public const int CADESCOM_DISPLAY_DATA_ATTRIBUTE = 2;
        public const int CADESCOM_ENCRYPTION_ALGORITHM_RC2 = 0;
        public const int CADESCOM_ENCRYPTION_ALGORITHM_RC4 = 1;
        public const int CADESCOM_ENCRYPTION_ALGORITHM_DES = 2;
        public const int CADESCOM_ENCRYPTION_ALGORITHM_3DES = 3;
        public const int CADESCOM_ENCRYPTION_ALGORITHM_AES = 4;
        public const int CADESCOM_ENCRYPTION_ALGORITHM_GOST_28147_89 = 25;
        public const int CADESCOM_HASH_ALGORITHM_SHA1 = 0;
        public const int CADESCOM_HASH_ALGORITHM_MD2 = 1;
        public const int CADESCOM_HASH_ALGORITHM_MD4 = 2;
        public const int CADESCOM_HASH_ALGORITHM_MD5 = 3;
        public const int CADESCOM_HASH_ALGORITHM_SHA_256 = 4;
        public const int CADESCOM_HASH_ALGORITHM_SHA_384 = 5;
        public const int CADESCOM_HASH_ALGORITHM_SHA_512 = 6;
        public const int CADESCOM_HASH_ALGORITHM_CP_GOST_3411 = 100;
        public const int CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_256 = 101;
        public const int CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_512 = 102;
        public const int CADESCOM_HASH_ALGORITHM_CP_GOST_3411_HMAC = 110;
        public const int CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_256_HMAC = 111;
        public const int CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_512_HMAC = 112;
        public const int CADESCOM_AllowNone = 0x00;
        public const int CADESCOM_AllowNoOutstandingRequest = 0x01;
        public const int CADESCOM_AllowUntrustedCertificate = 0x02;
        public const int CADESCOM_AllowUntrustedRoot = 0x04;
        public const int CADESCOM_SkipInstallToStore = 0x10000000;
        public const int ENABLE_CARRIER_TYPE_CSP = 0x01;
        public const int ENABLE_CARRIER_TYPE_FKC_NO_SM = 0x02;
        public const int ENABLE_CARRIER_TYPE_FKC_SM = 0x04;
        public const int ENABLE_ANY_CARRIER_TYPE = 0x07;
        public const int DISABLE_EVERY_CARRIER_OPERATION = 0x00;
        public const int ENABLE_CARRIER_OPEN_ENUM = 0x01;
        public const int ENABLE_CARRIER_CREATE = 0x02;
        public const int ENABLE_ANY_OPERATION = 0x03;
        public const int MEDIA_TYPE_REGISTRY = 0x00000001;
        public const int MEDIA_TYPE_HDIMAGE = 0x00000002;
        public const int MEDIA_TYPE_CLOUD = 0x00000004;
        public const int MEDIA_TYPE_SCARD = 0x00000008;
        public const int XCN_CRYPT_STRING_BASE64HEADER = 0;
        public const int AT_KEYEXCHANGE = 1;
        public const int AT_SIGNATURE = 2;
        public const int CAPICOM_ENCODE_BASE64 = 0;
        public const int CADESCOM_ENCODE_ANY = -1;
        public const int CAPICOM_EKU_SERVER_AUTH = 1;
        public const int CAPICOM_EKU_CLIENT_AUTH = 2;
        public const int CAPICOM_EKU_CODE_SIGNING = 3;
        public const int CAPICOM_EKU_EMAIL_PROTECTION = 4;
        public const int CAPICOM_EKU_SMARTCARD_LOGON = 5;
        public const int CAPICOM_EKU_ENCRYPTING_FILE_SYSTEM = 6;
        public const int CAPICOM_CERT_INFO_SUBJECT_EMAIL_NAME = 2;
        public const int CAPICOM_CERT_INFO_ISSUER_EMAIL_NAME = 3;
        public const int CAPICOM_CERT_INFO_SUBJECT_UPN = 4;
        public const int CAPICOM_CERT_INFO_ISSUER_UPN = 5;
        public const int CAPICOM_CERT_INFO_SUBJECT_DNS_NAME = 6;
        public const int CAPICOM_CERT_INFO_ISSUER_DNS_NAME = 7;
        public const int CAPICOM_PROPID_KEY_PROV_INFO = 2;
        public const int CAPICOM_ENCRYPTION_KEY_LENGTH_MAXIMUM = 0;
        public const int CAPICOM_ENCRYPTION_KEY_LENGTH_40_BITS = 1;
        public const int CAPICOM_ENCRYPTION_KEY_LENGTH_56_BITS = 2;
        public const int CAPICOM_ENCRYPTION_KEY_LENGTH_128_BITS = 3;
        public const int CAPICOM_ENCRYPTION_KEY_LENGTH_192_BITS = 4;
        public const int CAPICOM_ENCRYPTION_KEY_LENGTH_256_BITS = 5;
        public const int CAPICOM_DATA_ENCIPHERMENT_KEY_USAGE = 16;
        public const int CRYPT_MODE_CBCSTRICT = 1;
        public const int CRYPT_MODE_CNT = 3;
        public const int CRYPT_MODE_CBCRFC4357 = 31;
        public const int CRYPT_MODE_CTR = 32;
        public const int CRYPT_MODE_MGM = 33;
        public const int CRYPT_MODE_GCM = 34;
        public const int CRYPT_MODE_OMAC_CTR = 35;
        public const int CRYPT_MODE_WRAP = 36;
        public const int CRYPT_MODE_WRAP_PAD = 37;
        public const int PKCS5_PADDING = 1;
        public const int RANDOM_PADDING = 2;
        public const int ZERO_PADDING = 3;
        public const int ISO10126_PADDING = 4;
        public const int ANSI_X923_PADDING = 5;
        public const int TLS_1_0_PADDING = 6;
        public const int ISO_IEC_7816_4_PADDING = 7;
        public const int CADESCOM_PRODUCT_CSP = 0;
        public const int CADESCOM_PRODUCT_OCSP = 1;
        public const int CADESCOM_PRODUCT_TSP = 2;

        public const string CAPICOM_MY_STORE = "My";
        public const string CAPICOM_CA_STORE = "CA";
        public const string CAPICOM_ROOT_STORE = "Root";
        public const string CAPICOM_OTHER_STORE = "AddressBook";
        public const string XmlDsigGost3410UrlObsolete = "http://www.w3.org/2001/04/xmldsig-more#gostr34102001-gostr3411";
        public const string XmlDsigGost3411UrlObsolete = "http://www.w3.org/2001/04/xmldsig-more#gostr3411";
        public const string XmlDsigGost3410Url = "urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr34102001-gostr3411";
        public const string XmlDsigGost3411Url = "urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr3411";
        public const string XmlDsigGost3410Url2012256 = "urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr34102012-gostr34112012-256";
        public const string XmlDsigGost3411Url2012256 = "urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr34112012-256";
        public const string XmlDsigGost3410Url2012512 = "urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr34102012-gostr34112012-512";
        public const string XmlDsigGost3411Url2012512 = "urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr34112012-512";
    }
}