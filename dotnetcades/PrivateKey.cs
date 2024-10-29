using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class PrivateKey : IDisposable
    {
        IntPtr _CCadesPrivateKey = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_change_pin(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_set_cache_pin(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_container_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_unique_container_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_provider_name(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_provider_type(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_key_spec(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_is_default_pin(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_set_key_pin(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesPrivateKey_get_carrier_flags(IntPtr self, ref int result);

        public PrivateKey() 
        {
            int hresult = CCadesPrivateKey_create(ref _CCadesPrivateKey);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public PrivateKey(IntPtr m)
        {
            _CCadesPrivateKey = m;
        }
        public static explicit operator IntPtr(PrivateKey value)
        {
            return value._CCadesPrivateKey;
        }
        public void Dispose()
        {
            int hresult = CCadesPrivateKey_destroy(_CCadesPrivateKey);
            if (hresult != 0)
            {
                Console.WriteLine($"PrivateKey.Dispose() failed: {hresult}");
            }
        }

        public void ChangePin()
        {
            int hresult = CCadesPrivateKey_change_pin(_CCadesPrivateKey);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public bool CachePin
        {
            set
            {
                int piValue = Convert.ToInt32(value);
                int hresult = CCadesPrivateKey_set_cache_pin(_CCadesPrivateKey, piValue);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string ContainerName
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesPrivateKey_get_container_name(_CCadesPrivateKey, ref ptr);
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
        public string UniqueContainerName
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesPrivateKey_get_unique_container_name(_CCadesPrivateKey, ref ptr);
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
        public string ProviderName
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesPrivateKey_get_provider_name(_CCadesPrivateKey, ref ptr);
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
        public int ProviderType
        {
            get
            {
                int result = default;
                int hresult = CCadesPrivateKey_get_provider_type(_CCadesPrivateKey, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public int KeySpec
        {
            get
            {
                int result = default;
                int hresult = CCadesPrivateKey_get_key_spec(_CCadesPrivateKey, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public int CarrierFlags
        {
            get
            {
                int result = default;
                int hresult = CCadesPrivateKey_get_carrier_flags(_CCadesPrivateKey, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public bool IsDefaultPin
        {
            get
            {
                int result = default;
                int hresult = CCadesPrivateKey_get_is_default_pin(_CCadesPrivateKey, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public string KeyPin
        {
            set
            {
                int hresult = CCadesPrivateKey_set_key_pin(_CCadesPrivateKey, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
