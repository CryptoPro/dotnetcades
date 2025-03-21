﻿using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class About : IDisposable
    {
        IntPtr _CCadesAbout = IntPtr.Zero;
        bool _disposed;

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_create(ref IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_destroy(IntPtr self);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_version(IntPtr self, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_csp_name(IntPtr self, int dwProvType, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_major_version(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_minor_version(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_build_version(IntPtr self, ref int result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_plugin_version(IntPtr self, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_get_csp_version(IntPtr self, string ProvName, int ProvType, ref IntPtr result);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_media_filter(IntPtr self, int dwMediaType);

        [DllImport("libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesAbout_reader_filter(IntPtr self, int EnabledTypes, int EnabledOperations, string FilterRegexp);

        public About() 
        {
            int hresult = CCadesAbout_create(ref _CCadesAbout);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public About(IntPtr m)
        {
            _CCadesAbout = m;
        }
        public static explicit operator IntPtr(About value)
        {
            return value._CCadesAbout;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesAbout != IntPtr.Zero)
                {
                    int hresult = CCadesAbout_destroy(_CCadesAbout);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"About.Dispose() failed: {hresult}");
                    }
                    _CCadesAbout = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~About()
        {
            Dispose(false);
        }

        public string Version
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesAbout_get_version(_CCadesAbout, ref ptr);
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
        public string CSPName(int ProvType = 75)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesAbout_get_csp_name(_CCadesAbout, ProvType, ref ptr);
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
                int hresult = CCadesAbout_get_major_version(_CCadesAbout, ref result);
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
                int hresult = CCadesAbout_get_minor_version(_CCadesAbout, ref result);
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
                int hresult = CCadesAbout_get_build_version(_CCadesAbout, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        public void MediaFilter(int MediaType)
        {
            int hresult = CCadesAbout_media_filter(_CCadesAbout, MediaType);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public void ReaderFilter(int EnabledTypes, int EnabledOperations, string FilterRegexp)
        {
            int hresult = CCadesAbout_reader_filter(_CCadesAbout, EnabledTypes, EnabledOperations, FilterRegexp);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Version PluginVersion
        {
            get
            {
                IntPtr ptr = default;
                int hresult = CCadesAbout_get_plugin_version(_CCadesAbout, ref ptr);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                Version result = new Version(ptr);
                return result;
            }
        }
        public Version CSPVersion(string ProvName = "", int ProvType = 75)
        {
            IntPtr ptr = default;
            int hresult = CCadesAbout_get_csp_version(_CCadesAbout, ProvName, ProvType, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new Version(ptr);
        }
    }
}
