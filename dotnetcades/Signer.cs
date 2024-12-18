using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Signer : IDisposable
    {
        IntPtr _CCadesSigner = IntPtr.Zero;
        bool _disposed;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_authenticated_attributes2(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_unauthenticated_attributes(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_certificate(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_put_certificate(IntPtr self, IntPtr value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_put_options(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_options(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_ocsp_responses(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_crls(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_put_tsa_address(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_tsa_address(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_signature_timestamp_time(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_signing_time(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_put_key_pin(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_signature_status(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_get_check_certificate(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigner_put_check_certificate(IntPtr self, int value);

        public Signer() 
        {
            int hresult = CCadesSigner_create(ref _CCadesSigner);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Signer(IntPtr m)
        {
            _CCadesSigner = m;
        }
        public static explicit operator IntPtr(Signer value)
        {
            return value._CCadesSigner;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesSigner != IntPtr.Zero)
                {
                    int hresult = CCadesSigner_destroy(_CCadesSigner);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"Signer.Dispose() failed: {hresult}");
                    }
                    _CCadesSigner = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Signer()
        {
            Dispose(false);
        }

        public Attributes UnauthenticatedAttributes
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSigner_get_unauthenticated_attributes(_CCadesSigner, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Attributes(ptr);
            }
        }
        public Attributes AuthenticatedAttributes2
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSigner_get_authenticated_attributes2(_CCadesSigner, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Attributes(ptr);
            }
        }
        public Certificate Certificate
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSigner_get_certificate(_CCadesSigner, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Certificate(ptr);
            }

            set
            {
                int hresult = CCadesSigner_put_certificate(_CCadesSigner, (IntPtr)value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int Options
        {
            get
            {
                int result = default;
                int hresult = CCadesSigner_get_options(_CCadesSigner, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesSigner_put_options(_CCadesSigner, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public Blobs CRLs
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSigner_get_crls(_CCadesSigner, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Blobs(ptr);
            }
        }
        public Blobs OCSPResponses
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSigner_get_ocsp_responses(_CCadesSigner, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Blobs(ptr);
            }
        }
        public string TSAAddress
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesSigner_get_tsa_address(_CCadesSigner, ref ptr);
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

            set
            {
                int hresult = CCadesSigner_put_tsa_address(_CCadesSigner, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string SignatureTimeStampTime
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesSigner_get_signature_timestamp_time(_CCadesSigner, ref ptr);
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
        }
        public string SigningTime
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesSigner_get_signing_time(_CCadesSigner, ref ptr);
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
        }
        public string KeyPin
        {
            set
            {
                int hresult = CCadesSigner_put_key_pin(_CCadesSigner, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public SignatureStatus SignatureStatus
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSigner_get_signature_status(_CCadesSigner, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new SignatureStatus(ptr);
            }
        }
        public bool CheckCertificate
        {
            get
            {
                int result = default;
                int hresult = CCadesSigner_get_check_certificate(_CCadesSigner, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }

            set
            {
                int piValue = Convert.ToInt32(value);
                int hresult = CCadesSigner_put_check_certificate(_CCadesSigner, piValue);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
