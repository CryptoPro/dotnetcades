using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class SignedXML : IDisposable
    {
        IntPtr _CCadesSignedXML = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_get_signers(IntPtr self, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_put_content(IntPtr self, string value);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_get_content(IntPtr self, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_put_signature_type(IntPtr self, int value);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_put_signature_method(IntPtr self, string value);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_put_digest_method(IntPtr self, string value);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_sign(IntPtr self, IntPtr signer, string xpath, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSignedXML_verify(IntPtr self, string value, string xpath);

        public SignedXML() 
        {
            int hresult = CCadesSignedXML_create(ref _CCadesSignedXML);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public SignedXML(IntPtr m)
        {
            _CCadesSignedXML = m;
        }
        public static explicit operator IntPtr(SignedXML value)
        {
            return value._CCadesSignedXML;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesSignedXML != IntPtr.Zero)
                {
                    int hresult = CCadesSignedXML_destroy(_CCadesSignedXML);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"SignedXML.Dispose() failed: {hresult}");
                    }
                    _CCadesSignedXML = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~SignedXML()
        {
            Dispose(false);
        }

        public string Content
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesSignedXML_get_content(_CCadesSignedXML, ref ptr);
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
                int hresult = CCadesSignedXML_put_content(_CCadesSignedXML, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string DigestMethod
        {
            set
            {
                int hresult = CCadesSignedXML_put_digest_method(_CCadesSignedXML, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string SignatureMethod
        {
            set
            {
                int hresult = CCadesSignedXML_put_signature_method(_CCadesSignedXML, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int SignatureType
        {
            set
            {
                int hresult = CCadesSignedXML_put_signature_type(_CCadesSignedXML, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public Signers Signers
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesSignedXML_get_signers(_CCadesSignedXML, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Signers(ptr);
            }
        }
        public string Sign(Signer signer, string xpath = "")
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesSignedXML_sign(_CCadesSignedXML, (IntPtr)signer, xpath, ref ptr);
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
        public void Verify(string value, string xpath = "")
        {
            int hresult = CCadesSignedXML_verify(_CCadesSignedXML, value, xpath);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}
