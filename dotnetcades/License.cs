using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class License : IDisposable
    {
        IntPtr _CCadesLicense = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_get_serial_number(IntPtr self, int product, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_get_company_name(IntPtr self, int product, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_get_first_install_date(IntPtr self, int product, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_get_type(IntPtr self, int product, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_get_valid_to(IntPtr self, int product, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesLicense_set_license(IntPtr self, string serial, string user, string company);

        public License() 
        {
            int hresult = CCadesLicense_create(ref _CCadesLicense);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public License(IntPtr m)
        {
            _CCadesLicense = m;
        }
        public static explicit operator IntPtr(License value)
        {
            return value._CCadesLicense;
        }
        public void Dispose()
        {
            int hresult = CCadesLicense_destroy(_CCadesLicense);
            if (hresult != 0)
            {
                Console.WriteLine($"License.Dispose() failed: {hresult}");
            }
        }

        public string SerialNumber(int product = NC.CADESCOM_PRODUCT_CSP)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesLicense_get_serial_number(_CCadesLicense, product, ref ptr);
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
        public string FirstInstallDate(int product = NC.CADESCOM_PRODUCT_CSP)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesLicense_get_first_install_date(_CCadesLicense, product, ref ptr);
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
        public string CompanyName(int product = NC.CADESCOM_PRODUCT_CSP)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesLicense_get_company_name(_CCadesLicense, product, ref ptr);
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
        public string Type(int product = NC.CADESCOM_PRODUCT_CSP)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesLicense_get_type(_CCadesLicense, product, ref ptr);
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
        public string ValidTo(int product = NC.CADESCOM_PRODUCT_CSP)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesLicense_get_valid_to(_CCadesLicense, product, ref ptr);
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
        public void SetLicense(string serial, string user, string company)
        {
            int hresult = CCadesLicense_set_license(_CCadesLicense, serial, user, company);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}
