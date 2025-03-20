using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class CertificateStatus : IDisposable
    {
        IntPtr _CCadesCertificateStatus = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificateStatus_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificateStatus_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificateStatus_get_result(IntPtr self, ref int result);

        public CertificateStatus() 
        {
            int hresult = CCadesCertificateStatus_create(ref _CCadesCertificateStatus);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public CertificateStatus(IntPtr m)
        {
            _CCadesCertificateStatus = m;
        }
        public static explicit operator IntPtr(CertificateStatus value)
        {
            return value._CCadesCertificateStatus;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesCertificateStatus != IntPtr.Zero)
                {
                    int hresult = CCadesCertificateStatus_destroy(_CCadesCertificateStatus);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"CertificateStatus.Dispose() failed: {hresult}");
                    }
                    _CCadesCertificateStatus = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~CertificateStatus()
        {
            Dispose(false);
        }

        public bool Result
        {
            get
            {
                int result = default;
                int hresult = CCadesCertificateStatus_get_result(_CCadesCertificateStatus, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
    }
}
