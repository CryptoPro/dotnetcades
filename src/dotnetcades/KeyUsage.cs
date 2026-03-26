using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class KeyUsage : IDisposable
    {
        IntPtr _CCadesKeyUsage = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_present(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_critical(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_crl_sign_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_data_encipherment_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_decipher_only_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_digital_signature_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_encipher_only_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_key_agreement_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_key_cert_sign_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_key_encipherment_enabled(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesKeyUsage_get_is_non_repudiation_enabled(IntPtr self, ref int result);

        public KeyUsage() 
        {
            int hresult = CCadesKeyUsage_create(ref _CCadesKeyUsage);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public KeyUsage(IntPtr m)
        {
            _CCadesKeyUsage = m;
        }
        public static explicit operator IntPtr(KeyUsage value)
        {
            return value._CCadesKeyUsage;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesKeyUsage != IntPtr.Zero)
                {
                    int hresult = CCadesKeyUsage_destroy(_CCadesKeyUsage);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"KeyUsage.Dispose() failed: {hresult}");
                    }
                    _CCadesKeyUsage = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~KeyUsage()
        {
            Dispose(false);
        }

        public bool IsPresent
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_present(_CCadesKeyUsage, ref result);
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
                int hresult = CCadesKeyUsage_get_is_critical(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsCRLSignEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_crl_sign_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsDataEnciphermentEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_data_encipherment_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsDecipherOnlyEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_decipher_only_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsDigitalSignatureEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_digital_signature_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsEncipherOnlyEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_encipher_only_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsKeyAgreementEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_key_agreement_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsKeyCertSignEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_key_cert_sign_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsKeyEnciphermentEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_key_encipherment_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsNonRepudiationEnabled
        {
            get
            {
                int result = default;
                int hresult = CCadesKeyUsage_get_is_non_repudiation_enabled(_CCadesKeyUsage, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
    }
}
