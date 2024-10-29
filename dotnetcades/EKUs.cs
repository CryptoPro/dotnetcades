using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class EKUs : IDisposable
    {
        IntPtr _CCadesEKUs = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKUs_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKUs_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKUs_get_count(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesEKUs_get_item(IntPtr self, int value, ref IntPtr result);

        public EKUs() 
        {
            int hresult = CCadesEKUs_create(ref _CCadesEKUs);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public EKUs(IntPtr m)
        {
            _CCadesEKUs = m;
        }
        public static explicit operator IntPtr(EKUs value)
        {
            return value._CCadesEKUs;
        }
        public void Dispose()
        {
            int hresult = CCadesEKUs_destroy(_CCadesEKUs);
            if (hresult != 0)
            {
                Console.WriteLine($"EKUs.Dispose() failed: {hresult}");
            }
        }

        public int Count
        {
            get
            {
                int result = default;
                int hresult = CCadesEKUs_get_count(_CCadesEKUs, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public EKU Item(int value)
        {
            IntPtr ptr = default;
            int hresult = CCadesEKUs_get_item(_CCadesEKUs, value, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new EKU(ptr);
        }
    }
}
