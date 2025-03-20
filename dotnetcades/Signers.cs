using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Signers : IDisposable
    {
        IntPtr _CCadesSigners = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigners_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigners_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigners_get_count(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSigners_get_item(IntPtr self, int index, ref IntPtr result);

        public Signers() 
        {
            int hresult = CCadesSigners_create(ref _CCadesSigners);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Signers(IntPtr m)
        {
            _CCadesSigners = m;
        }
        public static explicit operator IntPtr(Signers value)
        {
            return value._CCadesSigners;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesSigners != IntPtr.Zero)
                {
                    int hresult = CCadesSigners_destroy(_CCadesSigners);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"Signers.Dispose() failed: {hresult}");
                    }
                    _CCadesSigners = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Signers()
        {
            Dispose(false);
        }

        public int Count
        {
            get
            {
                int result = default;
                int hresult = CCadesSigners_get_count(_CCadesSigners, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public Signer Item(int value)
        {
            IntPtr ptr = default;
            int hresult = CCadesSigners_get_item(_CCadesSigners, value, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new Signer(ptr);
        }
    }
}
