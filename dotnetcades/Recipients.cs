using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Recipients : IDisposable
    {
        IntPtr _CCadesRecipients = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_get_count(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_get_item(IntPtr self, int index, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_remove(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_add(IntPtr self, IntPtr value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesRecipients_clear(IntPtr self);

        public Recipients() 
        {
            int hresult = CCadesRecipients_create(ref _CCadesRecipients);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Recipients(IntPtr m)
        {
            _CCadesRecipients = m;
        }
        public static explicit operator IntPtr(Recipients value)
        {
            return value._CCadesRecipients;
        }
        public void Dispose()
        {
            int hresult = CCadesRecipients_destroy(_CCadesRecipients);
            if (hresult != 0)
            {
                Console.WriteLine($"Recipients.Dispose() failed: {hresult}");
            }
        }

        public Certificate Item(int index)
        {
            IntPtr ptr = default;
            int hresult = CCadesRecipients_get_item(_CCadesRecipients, index, ref ptr);
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
                int hresult = CCadesRecipients_get_count(_CCadesRecipients, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public void Add(Certificate value)
        {
            int hresult = CCadesRecipients_add(_CCadesRecipients, (IntPtr)value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Remove(int value)
        {
            int hresult = CCadesRecipients_remove(_CCadesRecipients, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Clear()
        {
            int hresult = CCadesRecipients_clear(_CCadesRecipients);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}
