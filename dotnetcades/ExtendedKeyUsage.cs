using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class ExtendedKeyUsage : IDisposable
    {
        IntPtr _CCadesExtendedKeyUsage = IntPtr.Zero;
        bool _disposed;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesExtendedKeyUsage_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesExtendedKeyUsage_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesExtendedKeyUsage_get_ekus(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesExtendedKeyUsage_get_is_present(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesExtendedKeyUsage_get_is_critical(IntPtr self, ref int result);

        public ExtendedKeyUsage() 
        {
            int hresult = CCadesExtendedKeyUsage_create(ref _CCadesExtendedKeyUsage);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public ExtendedKeyUsage(IntPtr m)
        {
            _CCadesExtendedKeyUsage = m;
        }
        public static explicit operator IntPtr(ExtendedKeyUsage value)
        {
            return value._CCadesExtendedKeyUsage;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesExtendedKeyUsage != IntPtr.Zero)
                {
                    int hresult = CCadesExtendedKeyUsage_destroy(_CCadesExtendedKeyUsage);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"ExtendedKeyUsage.Dispose() failed: {hresult}");
                    }
                    _CCadesExtendedKeyUsage = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~ExtendedKeyUsage()
        {
            Dispose(false);
        }

        public EKUs EKUs
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesExtendedKeyUsage_get_ekus(_CCadesExtendedKeyUsage, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new EKUs(ptr);
            }
        }
        public bool IsPresent
        {
            get
            {
                int result = default;
                int hresult = CCadesExtendedKeyUsage_get_is_present(_CCadesExtendedKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsCritical
        {
            get
            {
                int result = default;
                int hresult = CCadesExtendedKeyUsage_get_is_critical(_CCadesExtendedKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
    }
}
