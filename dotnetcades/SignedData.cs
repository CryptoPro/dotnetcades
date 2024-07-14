using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class SignedData : IDisposable
    {
        IntPtr _CCadesSignedData = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_get_certificates(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_get_signers(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_put_content(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_get_content(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_put_content_encoding(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_get_content_encoding(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_put_display_data(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_get_display_data(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_cosign(IntPtr self, IntPtr signer, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_sign(IntPtr self, IntPtr signer, int isDetached, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_verify(IntPtr self, string value, int isDetached, int flags);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_cosign_cades(IntPtr self, IntPtr signer, int CadesType, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_enhance_cades(IntPtr self, int CadesType, string TSAAddress, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_sign_cades(IntPtr self, IntPtr signer, int CadesType, int isDetached, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_verify_cades(IntPtr self, string value, int CadesType, int isDetached);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_cosign_hash(IntPtr self, IntPtr hashedData, IntPtr signer, int CadesType, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_sign_hash(IntPtr self, IntPtr hashedData, IntPtr signer, int CadesType, int EncodingType, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedData_verify_hash(IntPtr self, IntPtr hashedData, string value, int CadesType);

        public SignedData()
        {
            int hresult = CCadesSignedData_create(ref _CCadesSignedData);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public SignedData(IntPtr m)
        {
            _CCadesSignedData = m;
        }
        public static explicit operator IntPtr(SignedData value)
        {
            return value._CCadesSignedData;
        }
        public void Dispose()
        {
            int hresult = CCadesSignedData_destroy(_CCadesSignedData);
            if (hresult != 0)
            {
                Console.WriteLine($"SignedData.Dispose() failed: {hresult}");
            }
        }
        public Certificates Certificates
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                int hresult = CCadesSignedData_get_certificates(_CCadesSignedData, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                Certificates result = new Certificates(ptr);
                return result;
            }
        }
        public Signers Signers
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                int hresult = CCadesSignedData_get_signers(_CCadesSignedData, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                Signers result = new Signers(ptr);
                return result;
            }
        }
        public string Content
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesSignedData_get_content(_CCadesSignedData, ref ptr);
                    if (hresult != 0)
                    {
                        throw new Exception(NC.GetErrorMessage(hresult));
                    }
                    return Marshal.PtrToStringAuto(ptr);
                }
                finally
                {
                    NC.FreeString(ptr);
                }
            }
            set
            {
                int hresult = CCadesSignedData_put_content(_CCadesSignedData, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int ContentEncoding
        {
            get
            {
                int result = 0;
                int hresult = CCadesSignedData_get_content_encoding(_CCadesSignedData, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
            set
            {
                int hresult = CCadesSignedData_put_content_encoding(_CCadesSignedData, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int DisplayData
        {
            get
            {
                int result = 0;
                int hresult = CCadesSignedData_get_display_data(_CCadesSignedData, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
            set
            {
                int hresult = CCadesSignedData_put_display_data(_CCadesSignedData, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string CoSign(Signer signer, int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesSignedData_cosign(_CCadesSignedData, (IntPtr)signer, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public string Sign(Signer signer, bool isDetached = false, int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                var iIsDetached = Convert.ToInt32(isDetached);
                int hresult = CCadesSignedData_sign(_CCadesSignedData, (IntPtr)signer, iIsDetached, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public void Verify(string value, bool isDetached = false, int flags = 0)
        {
            int iIsDetached = Convert.ToInt32(isDetached);
            int hresult = CCadesSignedData_verify(_CCadesSignedData, value, iIsDetached, flags);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public string CoSignCades(Signer signer, int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1, int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesSignedData_cosign_cades(_CCadesSignedData, (IntPtr)signer, CadesType, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public string EnhanceCades(int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1, string TSAAddress = "", int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesSignedData_enhance_cades(_CCadesSignedData, CadesType, TSAAddress, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public string SignCades(Signer signer, int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1, bool isDetached = false, int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int iIsDetached = Convert.ToInt32(isDetached);
                int hresult = CCadesSignedData_sign_cades(_CCadesSignedData, (IntPtr)signer, CadesType, iIsDetached, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public void VerifyCades(string value, int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1, bool isDetached = false)
        {
            int iIsDetached = Convert.ToInt32(isDetached);
            int hresult = CCadesSignedData_verify_cades(_CCadesSignedData, value, CadesType, iIsDetached);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public string CoSignHash(HashedData hashedData, Signer signer, int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1, int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesSignedData_cosign_hash(_CCadesSignedData, (IntPtr)hashedData, (IntPtr)signer, CadesType, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public string SignHash(HashedData hashedData, Signer signer, int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1, int EncodingType = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesSignedData_sign_hash(_CCadesSignedData, (IntPtr)hashedData, (IntPtr)signer, CadesType, EncodingType, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return Marshal.PtrToStringAuto(ptr);
            }
            finally
            {
                NC.FreeString(ptr);
            }
        }
        public void VerifyHash(HashedData hashedData, string value, int CadesType = NC.CADESCOM_CADES_X_LONG_TYPE_1)
        {
            int hresult = CCadesSignedData_verify_hash(_CCadesSignedData, (IntPtr)hashedData, value, CadesType);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}