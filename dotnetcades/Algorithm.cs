using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Algorithm : IDisposable
    {
        IntPtr _CCadesAlgorithm = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAlgorithm_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAlgorithm_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAlgorithm_get_name(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAlgorithm_put_name(IntPtr self, int value);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAlgorithm_get_key_length(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAlgorithm_put_key_length(IntPtr self, int value);

        public Algorithm() 
        {
            int hresult = CCadesAlgorithm_create(ref _CCadesAlgorithm);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Algorithm(IntPtr m)
        {
            _CCadesAlgorithm = m;
        }
        public static explicit operator IntPtr(Algorithm value)
        {
            return value._CCadesAlgorithm;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesAlgorithm != IntPtr.Zero)
                {
                    int hresult = CCadesAlgorithm_destroy(_CCadesAlgorithm);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"Algorithm.Dispose() failed: {hresult}");
                    }
                    _CCadesAlgorithm = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Algorithm()
        {
            Dispose(false);
        }
        public int Name
        {
            get
            {
                int result = default;
                int hresult = CCadesAlgorithm_get_name(_CCadesAlgorithm, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesAlgorithm_put_name(_CCadesAlgorithm, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int KeyLength
        {
            get
            {
                int result = default;
                int hresult = CCadesAlgorithm_get_key_length(_CCadesAlgorithm, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesAlgorithm_put_key_length(_CCadesAlgorithm, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
