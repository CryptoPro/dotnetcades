using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Attribute : IDisposable
    {
        IntPtr _CCadesAttribute = IntPtr.Zero;
        bool _disposed;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_get_oid(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_put_oid(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_get_value(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_put_value(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_get_name(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_put_name(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_get_value_encoding(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAttribute_put_value_encoding(IntPtr self, int value);

        public Attribute() 
        {
            int hresult = CCadesAttribute_create(ref _CCadesAttribute);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Attribute(IntPtr m)
        {
            _CCadesAttribute = m;
        }
        public static explicit operator IntPtr(Attribute value)
        {
            return value._CCadesAttribute;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesAttribute != IntPtr.Zero)
                {
                    int hresult = CCadesAttribute_destroy(_CCadesAttribute);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"Attribute.Dispose() failed: {hresult}");
                    }
                    _CCadesAttribute = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Attribute()
        {
            Dispose(false);
        }

        public OID OID
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesAttribute_get_oid(_CCadesAttribute, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return new OID(ptr);
            }
        }
        public void set_OID(string value)
        {
            int hresult = CCadesAttribute_put_oid(_CCadesAttribute, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public string Value
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesAttribute_get_value(_CCadesAttribute, ref ptr);
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
                int hresult = CCadesAttribute_put_value(_CCadesAttribute, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int Name
        {
            get
            {
                int result = default;
                int hresult = CCadesAttribute_get_name(_CCadesAttribute, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesAttribute_put_name(_CCadesAttribute, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public int ValueEncoding
        {
            get
            {
                int result = default;
                int hresult = CCadesAttribute_get_value_encoding(_CCadesAttribute, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }

            set
            {
                int hresult = CCadesAttribute_put_value_encoding(_CCadesAttribute, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
