using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class EnvelopedData : IDisposable
    {
        IntPtr _CCadesEnvelopedData = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_get_algorithm(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_put_content(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_get_content(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_put_content_encoding(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_get_content_encoding(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_get_recipients(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_encrypt(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_decrypt(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_stream_encrypt(IntPtr self, string value, int isFinal, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEnvelopedData_stream_decrypt(IntPtr self, string value, int isFinal, ref IntPtr result);

        public EnvelopedData() 
        {
            int hresult = CCadesEnvelopedData_create(ref _CCadesEnvelopedData);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public EnvelopedData(IntPtr m)
        {
            _CCadesEnvelopedData = m;
        }
        public void Dispose()
        {
            int hresult = CCadesEnvelopedData_destroy(_CCadesEnvelopedData);
            if (hresult != 0)
            {
                Console.WriteLine($"EnvelopedData.Dispose() failed: {hresult}");
            }
        }
        public Algorithm Algorithm
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                int hresult = CCadesEnvelopedData_get_algorithm(_CCadesEnvelopedData, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                Algorithm result = new Algorithm(ptr);
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
                    int hresult = CCadesEnvelopedData_get_content(_CCadesEnvelopedData, ref ptr);
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
                int hresult = CCadesEnvelopedData_put_content(_CCadesEnvelopedData, value);
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
                int hresult = CCadesEnvelopedData_get_content_encoding(_CCadesEnvelopedData, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
            set
            {
                int hresult = CCadesEnvelopedData_put_content_encoding(_CCadesEnvelopedData, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public Recipients Recipients
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                int hresult = CCadesEnvelopedData_get_recipients(_CCadesEnvelopedData, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                Recipients result = new Recipients(ptr);
                return result;
            }
        }
        public string Encrypt(int encoding = NC.CADESCOM_ENCODE_BASE64)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesEnvelopedData_encrypt(_CCadesEnvelopedData, encoding, ref ptr);
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
        public void Decrypt(string value)
        {
            int hresult = CCadesEnvelopedData_decrypt(_CCadesEnvelopedData, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public string StreamEncrypt(string block, bool isFinal)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                var iIsFinal = Convert.ToInt32(isFinal);
                int hresult = CCadesEnvelopedData_stream_encrypt(_CCadesEnvelopedData, block, iIsFinal, ref ptr);
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
        public string StreamDecrypt(string block, bool isFinal)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                var iIsFinal = Convert.ToInt32(isFinal);
                int hresult = CCadesEnvelopedData_stream_decrypt(_CCadesEnvelopedData, block, iIsFinal, ref ptr);
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
    }
}
