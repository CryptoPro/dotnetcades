using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Blobs : IDisposable
    {
        IntPtr _CCadesBlobs = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_get_item(IntPtr self, int value, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_get_count(IntPtr self, ref int result);

        public Blobs() 
        {
            int hresult = CCadesBlobs_create(ref _CCadesBlobs);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Blobs(IntPtr m)
        {
            _CCadesBlobs = m;
        }
        public static explicit operator IntPtr(Blobs value)
        {
            return value._CCadesBlobs;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesBlobs != IntPtr.Zero)
                {
                    int hresult = CCadesBlobs_destroy(_CCadesBlobs);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"Blobs.Dispose() failed: {hresult}");
                    }
                    _CCadesBlobs = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Blobs()
        {
            Dispose(false);
        }

        public string Item(int value)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesBlobs_get_item(_CCadesBlobs, value, ref ptr);
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
        public int Count
        {
            get
            {
                int result = default;
                int hresult = CCadesBlobs_get_count(_CCadesBlobs, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
    }
}
