using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class CertificateStatus : IDisposable
    {
        IntPtr _CCadesCertificateStatus = IntPtr.Zero;
        [DllImport("../ccades/libccades")]
        public static extern int CCadesCertificateStatus_create(ref IntPtr self);
        [DllImport("../ccades/libccades")]
        public static extern int CCadesCertificateStatus_destroy(IntPtr self);
        [DllImport("../ccades/libccades")]
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
        public void Dispose()
        {
            int hresult = CCadesCertificateStatus_destroy(_CCadesCertificateStatus);
            if (hresult != 0)
            {
                Console.WriteLine($"CertificateStatus.Dispose() failed: {hresult}");
            }
        }
        public bool Result
        {
            get
            {
                int result = 0;
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

