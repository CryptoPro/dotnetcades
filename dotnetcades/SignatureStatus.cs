using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class SignatureStatus : IDisposable
    {
        IntPtr _CCadesSignatureStatus = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignatureStatus_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignatureStatus_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignatureStatus_is_valid(IntPtr self, ref int result);

        public SignatureStatus() 
        {
            int hresult = CCadesSignatureStatus_create(ref _CCadesSignatureStatus);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public SignatureStatus(IntPtr m)
        {
            _CCadesSignatureStatus = m;
        }
        public static explicit operator IntPtr(SignatureStatus value)
        {
            return value._CCadesSignatureStatus;
        }
        public void Dispose()
        {
            int hresult = CCadesSignatureStatus_destroy(_CCadesSignatureStatus);
            if (hresult != 0)
            {
                Console.WriteLine($"SignatureStatus.Dispose() failed: {hresult}");
            }
        }

        public bool IsValid
        {
            get
            {
                int result = default;
                int hresult = CCadesSignatureStatus_is_valid(_CCadesSignatureStatus, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
    }
}
