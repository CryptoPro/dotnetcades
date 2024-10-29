using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class OID : IDisposable
    {
        IntPtr _CCadesOID = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_get_name(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_put_name(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_get_friendly_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_put_friendly_name(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_get_value(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesOID_put_value(IntPtr self, string value);

        public OID() 
        {
            int hresult = CCadesOID_create(ref _CCadesOID);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public OID(IntPtr m)
        {
            _CCadesOID = m;
        }
        public static explicit operator IntPtr(OID value)
        {
            return value._CCadesOID;
        }
        public void Dispose()
        {
            int hresult = CCadesOID_destroy(_CCadesOID);
            if (hresult != 0)
            {
                Console.WriteLine($"OID.Dispose() failed: {hresult}");
            }
        }

        public int Name
        {
            get
            {
                int result = default;
                int hresult = CCadesOID_get_name(_CCadesOID, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesOID_put_name(_CCadesOID, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string FriendlyName
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesOID_get_friendly_name(_CCadesOID, ref ptr);
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
                int hresult = CCadesOID_put_friendly_name(_CCadesOID, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string Value
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesOID_get_value(_CCadesOID, ref ptr);
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
                int hresult = CCadesOID_put_value(_CCadesOID, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
