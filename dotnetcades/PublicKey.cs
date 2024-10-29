using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class PublicKey : IDisposable
    {
        IntPtr _CCadesPublicKey = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPublicKey_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPublicKey_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPublicKey_get_algorithm(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPublicKey_get_encoded_key(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPublicKey_get_encoded_parameters(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPublicKey_get_length(IntPtr self, ref int result);

        public PublicKey() 
        {
            int hresult = CCadesPublicKey_create(ref _CCadesPublicKey);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public PublicKey(IntPtr m)
        {
            _CCadesPublicKey = m;
        }
        public static explicit operator IntPtr(PublicKey value)
        {
            return value._CCadesPublicKey;
        }
        public void Dispose()
        {
            int hresult = CCadesPublicKey_destroy(_CCadesPublicKey);
            if (hresult != 0)
            {
                Console.WriteLine($"PublicKey.Dispose() failed: {hresult}");
            }
        }

        public OID Algorithm
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesPublicKey_get_algorithm(_CCadesPublicKey, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new OID(ptr);
            }
        }
        public EncodedData EncodedKey
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesPublicKey_get_encoded_key(_CCadesPublicKey, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new EncodedData(ptr);
            }
        }
        public EncodedData EncodedParameters
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesPublicKey_get_encoded_parameters(_CCadesPublicKey, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new EncodedData(ptr);
            }
        }
        public int Length
        {
            get
            {
                int result = default;
                int hresult = CCadesPublicKey_get_length(_CCadesPublicKey, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
    }
}