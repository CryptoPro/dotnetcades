using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class SignatureStatus : IDisposable
    {
        IntPtr _CCadesSignatureStatus = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignatureStatus_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignatureStatus_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
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
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesSignatureStatus != IntPtr.Zero)
                {
                    int hresult = CCadesSignatureStatus_destroy(_CCadesSignatureStatus);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"SignatureStatus.Dispose() failed: {hresult}");
                    }
                    _CCadesSignatureStatus = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~SignatureStatus()
        {
            Dispose(false);
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
