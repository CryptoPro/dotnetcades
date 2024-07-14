using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Certificate : IDisposable
    {
        IntPtr _CCadesCertificate = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_info(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_has_private_key(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_is_valid(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_extended_key_usage(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_key_usage(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_export(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_import(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_thumbprint(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_serial_number(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_subject_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_issuer_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_version(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_valid_to_date(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_get_valid_from_date(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_basic_constraints(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_public_key(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_private_key(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificate_find_private_key(IntPtr self);

        public Certificate() 
        {
            int hresult = CCadesCertificate_create(ref _CCadesCertificate);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Certificate(IntPtr m)
        {
            _CCadesCertificate = m;
        }
        public static explicit operator IntPtr(Certificate value)
        {
            return value._CCadesCertificate;
        }
        public void Dispose()
        {
            int hresult = CCadesCertificate_destroy(_CCadesCertificate);
            if (hresult != 0)
            {
                Console.WriteLine($"Certificate.Dispose() failed: {hresult}");
            }
        }
        public string IssuerName
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesCertificate_get_issuer_name(_CCadesCertificate, ref ptr);
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
        public string SerialNumber
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesCertificate_get_serial_number(_CCadesCertificate, ref ptr);
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
        public string SubjectName
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesCertificate_get_subject_name(_CCadesCertificate, ref ptr);
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
        public string Thumbprint
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesCertificate_get_thumbprint(_CCadesCertificate, ref ptr);
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
        public string ValidFromDate
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesCertificate_get_valid_from_date(_CCadesCertificate, ref ptr);
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
        public string ValidToDate
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesCertificate_get_valid_to_date(_CCadesCertificate, ref ptr);
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
        public int Version
        {
            get
            {
                int result = 0;
                int hresult = CCadesCertificate_get_version(_CCadesCertificate, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public PrivateKey PrivateKey
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                int hresult = CCadesCertificate_private_key(_CCadesCertificate, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                PrivateKey result = new PrivateKey(ptr);
                return result;
            }
        }
        public PublicKey PublicKey()
        {
            IntPtr ptr = IntPtr.Zero;
            int hresult = CCadesCertificate_public_key(_CCadesCertificate, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            PublicKey result = new PublicKey(ptr);
            return result;
        }
        public ExtendedKeyUsage ExtendedKeyUsage()
        {
            IntPtr ptr = IntPtr.Zero;
            int hresult = CCadesCertificate_extended_key_usage(_CCadesCertificate, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            ExtendedKeyUsage result = new ExtendedKeyUsage(ptr);
            return result;
        }
        public KeyUsage KeyUsage()
        {
            IntPtr ptr = IntPtr.Zero;
            int hresult = CCadesCertificate_key_usage(_CCadesCertificate, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            KeyUsage result = new KeyUsage(ptr);
            return result;
        }
        public BasicConstraints BasicConstraints()
        {
            IntPtr ptr = IntPtr.Zero;
            int hresult = CCadesCertificate_basic_constraints(_CCadesCertificate, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            BasicConstraints result = new BasicConstraints(ptr);
            return result;
        }
        public string Export(int encoding)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesCertificate_export(_CCadesCertificate, encoding, ref ptr);
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
        public string GetInfo(int InfoType)
        {
            IntPtr ptr = IntPtr.Zero;
            try
            {
                int hresult = CCadesCertificate_get_info(_CCadesCertificate, InfoType, ref ptr);
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
        public bool HasPrivateKey()
        {
            int result = 0;
            int hresult = CCadesCertificate_has_private_key(_CCadesCertificate, ref result);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return result != 0;
        }
        public void FindPrivateKey()
        {
            int hresult = CCadesCertificate_find_private_key(_CCadesCertificate);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Import(string value)
        {
            int hresult = CCadesCertificate_import(_CCadesCertificate, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public CertificateStatus IsValid()
        {
            IntPtr ptr = IntPtr.Zero;
            int hresult = CCadesCertificate_is_valid(_CCadesCertificate, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            CertificateStatus result = new CertificateStatus(ptr);
            return result;
        }
    }
}
