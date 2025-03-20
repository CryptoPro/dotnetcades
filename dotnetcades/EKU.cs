using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class EKU : IDisposable
    {
        IntPtr _CCadesEKU = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKU_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKU_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKU_get_name(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKU_put_name(IntPtr self, int value);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKU_get_oid(IntPtr self, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKU_put_oid(IntPtr self, string value);

        public EKU() 
        {
            int hresult = CCadesEKU_create(ref _CCadesEKU);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public EKU(IntPtr m)
        {
            _CCadesEKU = m;
        }
        public static explicit operator IntPtr(EKU value)
        {
            return value._CCadesEKU;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesEKU != IntPtr.Zero)
                {
                    int hresult = CCadesEKU_destroy(_CCadesEKU);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"EKU.Dispose() failed: {hresult}");
                    }
                    _CCadesEKU = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~EKU()
        {
            Dispose(false);
        }

        public int Name
        {
            get
            {
                int result = default;
                int hresult = CCadesEKU_get_name(_CCadesEKU, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesEKU_put_name(_CCadesEKU, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string OID
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesEKU_get_oid(_CCadesEKU, ref ptr);
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
                int hresult = CCadesEKU_put_oid(_CCadesEKU, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
