using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class EncodedData : IDisposable
    {
        IntPtr _CCadesEncodedData = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEncodedData_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEncodedData_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEncodedData_format(IntPtr self, int value, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEncodedData_get_value(IntPtr self, int encoding, ref IntPtr result);

        public EncodedData() 
        {
            int hresult = CCadesEncodedData_create(ref _CCadesEncodedData);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public EncodedData(IntPtr m)
        {
            _CCadesEncodedData = m;
        }
        public static explicit operator IntPtr(EncodedData value)
        {
            return value._CCadesEncodedData;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesEncodedData != IntPtr.Zero)
                {
                    int hresult = CCadesEncodedData_destroy(_CCadesEncodedData);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"EncodedData.Dispose() failed: {hresult}");
                    }
                    _CCadesEncodedData = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~EncodedData()
        {
            Dispose(false);
        }

        public string Format(bool bMultiline = false)
        {
            IntPtr ptr = default;
            try
            {
                int value = Convert.ToInt32(bMultiline);
                int hresult = CCadesEncodedData_format(_CCadesEncodedData, value, ref ptr);
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
        public string Value(int encoding)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesEncodedData_get_value(_CCadesEncodedData, encoding, ref ptr);
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
