using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class RawSignature : IDisposable
    {
        IntPtr _CCadesRawSignature = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRawSignature_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRawSignature_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRawSignature_sign_hash(IntPtr self, IntPtr hashedData, IntPtr signCert, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRawSignature_verify_hash(IntPtr self, IntPtr hashedData, IntPtr signCert, string value);

        public RawSignature() 
        {
            int hresult = CCadesRawSignature_create(ref _CCadesRawSignature);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public RawSignature(IntPtr m)
        {
            _CCadesRawSignature = m;
        }
        public static explicit operator IntPtr(RawSignature value)
        {
            return value._CCadesRawSignature;
        }
        public void Dispose()
        {
            int hresult = CCadesRawSignature_destroy(_CCadesRawSignature);
            if (hresult != 0)
            {
                Console.WriteLine($"RawSignature.Dispose() failed: {hresult}");
            }
        }
        public string SignHash(HashedData hashedData, Certificate signCert)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesRawSignature_sign_hash(_CCadesRawSignature, (IntPtr)hashedData, (IntPtr)signCert, ref ptr);
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
        public void VerifyHash(HashedData hashedData, Certificate signCert, string value)
        {
            int hresult = CCadesRawSignature_verify_hash(_CCadesRawSignature, (IntPtr)hashedData, (IntPtr)signCert, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}
