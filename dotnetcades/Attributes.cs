using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Attributes : IDisposable
    {
        IntPtr _CCadesAttributes = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_get_item(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_get_count(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_remove(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_add(IntPtr self, IntPtr value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttributes_clear(IntPtr self);

        public Attributes() 
        {
            int hresult = CCadesAttributes_create(ref _CCadesAttributes);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Attributes(IntPtr m)
        {
            _CCadesAttributes = m;
        }
        public static explicit operator IntPtr(Attributes value)
        {
            return value._CCadesAttributes;
        }
        public void Dispose()
        {
            int hresult = CCadesAttributes_destroy(_CCadesAttributes);
            if (hresult != 0)
            {
                Console.WriteLine($"Attributes.Dispose() failed: {hresult}");
            }
        }

        public Attribute Item(int value)
        {
            IntPtr ptr = default;
            int hresult = CCadesAttributes_get_item(_CCadesAttributes, value, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new Attribute(ptr);
        }
        public int Count
        {
            get
            {
                int result = default;
                int hresult = CCadesAttributes_get_count(_CCadesAttributes, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public void Add(Attribute value)
        {
            int hresult = CCadesAttributes_add(_CCadesAttributes, (IntPtr)value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Remove(int value)
        {
            int hresult = CCadesAttributes_remove(_CCadesAttributes, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Clear()
        {
            int hresult = CCadesAttributes_clear(_CCadesAttributes);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}
