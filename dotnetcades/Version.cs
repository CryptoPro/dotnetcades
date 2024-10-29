using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Version : IDisposable
    {
        IntPtr _CCadesVersion = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesVersion_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesVersion_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesVersion_to_string(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesVersion_get_major_version(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesVersion_get_minor_version(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesVersion_get_build_version(IntPtr self, ref int result);

        public Version() 
        {
            int hresult = CCadesVersion_create(ref _CCadesVersion);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Version(IntPtr m)
        {
            _CCadesVersion = m;
        }
        public static explicit operator IntPtr(Version value)
        {
            return value._CCadesVersion;
        }
        public void Dispose()
        {
            int hresult = CCadesVersion_destroy(_CCadesVersion);
            if (hresult != 0)
            {
                Console.WriteLine($"Version.Dispose() failed: {hresult}");
            }
        }

        public string toString()
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesVersion_to_string(_CCadesVersion, ref ptr);
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
        public int MajorVersion
        {
            get
            {
                int result = default;
                int hresult = CCadesVersion_get_major_version(_CCadesVersion, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public int MinorVersion
        {
            get
            {
                int result = default;
                int hresult = CCadesVersion_get_minor_version(_CCadesVersion, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public int BuildVersion
        {
            get
            {
                int result = default;
                int hresult = CCadesVersion_get_build_version(_CCadesVersion, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
    }
}
