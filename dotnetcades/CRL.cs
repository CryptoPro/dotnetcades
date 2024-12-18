using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class CRL : IDisposable
    {
        IntPtr _CCadesCRL = IntPtr.Zero;
        bool _disposed;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_import(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_export(IntPtr self, int encoding, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_get_issuer_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_get_this_update(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_get_next_update(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_get_thumbprint(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCRL_get_auth_key_id(IntPtr self, ref IntPtr result);

        public CRL() 
        {
            int hresult = CCadesCRL_create(ref _CCadesCRL);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public CRL(IntPtr m)
        {
            _CCadesCRL = m;
        }
        public static explicit operator IntPtr(CRL value)
        {
            return value._CCadesCRL;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesCRL != IntPtr.Zero)
                {
                    int hresult = CCadesCRL_destroy(_CCadesCRL);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"CRL.Dispose() failed: {hresult}");
                    }
                    _CCadesCRL = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~CRL()
        {
            Dispose(false);
        }

        public void Import(string value)
        {
            int hresult = CCadesCRL_import(_CCadesCRL, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public string Export(int encoding)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesCRL_export(_CCadesCRL, encoding, ref ptr);
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
        public string AuthKeyId
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesCRL_get_auth_key_id(_CCadesCRL, ref ptr);
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
        public string IssuerName
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesCRL_get_issuer_name(_CCadesCRL, ref ptr);
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
        public string ThisUpdate
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesCRL_get_this_update(_CCadesCRL, ref ptr);
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
        public string NextUpdate
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesCRL_get_next_update(_CCadesCRL, ref ptr);
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
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesCRL_get_thumbprint(_CCadesCRL, ref ptr);
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
    }
}
