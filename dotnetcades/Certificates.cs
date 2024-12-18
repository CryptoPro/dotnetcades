using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Certificates : IDisposable
    {
        IntPtr _CCadesCertificates = IntPtr.Zero;
        bool _disposed;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_get_item(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_get_count(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_find_s(IntPtr self, int FindType, string Criteria, int ValidOnly, ref IntPtr result);

        public Certificates() 
        {
            int hresult = CCadesCertificates_create(ref _CCadesCertificates);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Certificates(IntPtr m)
        {
            _CCadesCertificates = m;
        }
        public static explicit operator IntPtr(Certificates value)
        {
            return value._CCadesCertificates;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesCertificates != IntPtr.Zero)
                {
                    int hresult = CCadesCertificates_destroy(_CCadesCertificates);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"Certificates.Dispose() failed: {hresult}");
                    }
                    _CCadesCertificates = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Certificates()
        {
            Dispose(false);
        }

        public Certificate Item(int value)
        {
            IntPtr ptr = default;
            int hresult = CCadesCertificates_get_item(_CCadesCertificates, value, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new Certificate(ptr);
        }
        public int Count
        {
            get
            {
                int result = default;
                int hresult = CCadesCertificates_get_count(_CCadesCertificates, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public Certificates Find(int FindType, string Criteria, bool ValidOnly = false)
        {
            IntPtr ptr = default;
            int arg_ValidOnly = Convert.ToInt32(ValidOnly);
            int hresult = CCadesCertificates_find_s(_CCadesCertificates, FindType, Criteria, arg_ValidOnly, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new Certificates(ptr);
        }
    }
}
