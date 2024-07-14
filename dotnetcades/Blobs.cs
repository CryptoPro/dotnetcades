using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Blobs : IDisposable
    {
        IntPtr _CCadesBlobs = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBlobs_get_item(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
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
        public void Dispose()
        {
            int hresult = CCadesBlobs_destroy(_CCadesBlobs);
            if (hresult != 0)
            {
                Console.WriteLine($"Blobs.Dispose() failed: {hresult}");
            }
        }
        public string Item(int value)
        {
            IntPtr ptr = IntPtr.Zero;
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
                int result = 0;
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



