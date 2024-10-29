using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Store : IDisposable
    {
        IntPtr _CCadesStore = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_open(IntPtr self, int location, string name, int mode);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_close(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_add(IntPtr self, IntPtr certificate);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_add_crl(IntPtr self, IntPtr crl);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_get_certificates(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_get_location(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesStore_get_name(IntPtr self, ref IntPtr result);

        public Store() 
        {
            int hresult = CCadesStore_create(ref _CCadesStore);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Store(IntPtr m)
        {
            _CCadesStore = m;
        }
        public static explicit operator IntPtr(Store value)
        {
            return value._CCadesStore;
        }
        public void Dispose()
        {
            int hresult = CCadesStore_destroy(_CCadesStore);
            if (hresult != 0)
            {
                Console.WriteLine($"Store.Dispose() failed: {hresult}");
            }
        }

        public void Open(int Location = NC.CADESCOM_CURRENT_USER_STORE, string Name = NC.CAPICOM_MY_STORE, int Mode = NC.CAPICOM_STORE_OPEN_READ_ONLY)
        {
            int hresult = CCadesStore_open(_CCadesStore, Location, Name, Mode);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Close()
        {
            int hresult = CCadesStore_close(_CCadesStore);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void Add(Certificate certificate)
        {
            int hresult = CCadesStore_add(_CCadesStore, (IntPtr)certificate);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void AddCRL(CRL crl)
        {
            int hresult = CCadesStore_add_crl(_CCadesStore, (IntPtr)crl);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Certificates Certificates
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesStore_get_certificates(_CCadesStore, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new Certificates(ptr);
            }
        }
        public int Location
        {
            get
            {
                int result = default;
                int hresult = CCadesStore_get_location(_CCadesStore, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public string Name
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesStore_get_name(_CCadesStore, ref ptr);
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
}
