using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class ExtendedKeyUsage : IDisposable
    {
        IntPtr _CCadesExtendedKeyUsage = IntPtr.Zero;

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
        public void Dispose()
        {
            int hresult = CCadesExtendedKeyUsage_destroy(_CCadesExtendedKeyUsage);
            if (hresult != 0)
            {
                Console.WriteLine($"ExtendedKeyUsage.Dispose() failed: {hresult}");
            }
        }
        public EKUs EKUs
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                int hresult = CCadesExtendedKeyUsage_get_ekus(_CCadesExtendedKeyUsage, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                EKUs result = new EKUs(ptr);
                return result;
            }
        }
        public bool IsPresent
        {
            get
            {
                int result = 0;
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
                int result = 0;
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




