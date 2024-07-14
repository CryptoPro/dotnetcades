using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class HashedData : IDisposable
    {
        IntPtr _CCadesHashedData = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_put_algorithm(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_get_algorithm(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_get_value(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_put_data_encoding(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_get_data_encoding(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_get_key(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_put_key(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_hash(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesHashedData_set_hash_value(IntPtr self, string value);

        public HashedData()
        {
            int hresult = CCadesHashedData_create(ref _CCadesHashedData);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public HashedData(IntPtr m)
        {
            _CCadesHashedData = m;
        }
        public static explicit operator IntPtr(HashedData value)
        {
            return value._CCadesHashedData;
        }
        public void Dispose()
        {
            int hresult = CCadesHashedData_destroy(_CCadesHashedData);
            if (hresult != 0)
            {
                Console.WriteLine($"HashedData.Dispose() failed: {hresult}");
            }
        }
        public int Algorithm
        {
            get
            {
                int result = 0;
                int hresult = CCadesHashedData_get_algorithm(_CCadesHashedData, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
            set
            {
                int hresult = CCadesHashedData_put_algorithm(_CCadesHashedData, value);
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
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesHashedData_get_value(_CCadesHashedData, ref ptr);
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
        public int DataEncoding
        {
            get
            {
                int result = 0;
                int hresult = CCadesHashedData_get_data_encoding(_CCadesHashedData, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
            set
            {
                int hresult = CCadesHashedData_put_data_encoding(_CCadesHashedData, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string Key
        {
            get
            {
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    int hresult = CCadesHashedData_get_key(_CCadesHashedData, ref ptr);
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
                int hresult = CCadesHashedData_put_key(_CCadesHashedData, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public void Hash(string value)
        {
            int hresult = CCadesHashedData_hash(_CCadesHashedData, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void SetHashValue(string value)
        {
            int hresult = CCadesHashedData_set_hash_value(_CCadesHashedData, value);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
    }
}