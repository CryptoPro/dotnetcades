using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class SymmetricAlgorithm : IDisposable
    {
        IntPtr _CCadesSymmetricAlgorithm = IntPtr.Zero;
        bool _disposed;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_put_divers_data(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_get_divers_data(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_put_iv(IntPtr self, string value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_get_iv(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_import_key(IntPtr self, string value, IntPtr certificate, string password);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_export_key(IntPtr self, IntPtr certificate, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_generate_key(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_diversify_key(IntPtr self, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_encrypt(IntPtr self, string value, int isFinal, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_decrypt(IntPtr self, string value, int isFinal, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesSymmetricAlgorithm_put_legacy_plugin_symmetric_export(IntPtr self, int value);

        public SymmetricAlgorithm() 
        {
            int hresult = CCadesSymmetricAlgorithm_create(ref _CCadesSymmetricAlgorithm);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public SymmetricAlgorithm(IntPtr m)
        {
            _CCadesSymmetricAlgorithm = m;
        }
        public static explicit operator IntPtr(SymmetricAlgorithm value)
        {
            return value._CCadesSymmetricAlgorithm;
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (_CCadesSymmetricAlgorithm != IntPtr.Zero)
                {
                    int hresult = CCadesSymmetricAlgorithm_destroy(_CCadesSymmetricAlgorithm);
                    if (hresult != 0)
                    {
                        Console.WriteLine($"SymmetricAlgorithm.Dispose() failed: {hresult}");
                    }
                    _CCadesSymmetricAlgorithm = IntPtr.Zero;
                }
                _disposed = true;
            }
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~SymmetricAlgorithm()
        {
            Dispose(false);
        }

        public string DiversData
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesSymmetricAlgorithm_get_divers_data(_CCadesSymmetricAlgorithm, ref ptr);
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
                int hresult = CCadesSymmetricAlgorithm_put_divers_data(_CCadesSymmetricAlgorithm, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public string IV
        {
            get
            {
                IntPtr ptr = default;
                try
                {
                    int hresult = CCadesSymmetricAlgorithm_get_iv(_CCadesSymmetricAlgorithm, ref ptr);
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
                int hresult = CCadesSymmetricAlgorithm_put_iv(_CCadesSymmetricAlgorithm, value);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public void GenerateKey(int Algorithm)
        {
            int hresult = CCadesSymmetricAlgorithm_generate_key(_CCadesSymmetricAlgorithm, Algorithm);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public SymmetricAlgorithm DiversifyKey()
        {
            IntPtr ptr = default;
            int hresult = CCadesSymmetricAlgorithm_diversify_key(_CCadesSymmetricAlgorithm, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            return new SymmetricAlgorithm(ptr);
        }
        public string ExportKey(Certificate certificate)
        {
            IntPtr ptr = default;
            try
            {
                int hresult = CCadesSymmetricAlgorithm_export_key(_CCadesSymmetricAlgorithm, (IntPtr)certificate, ref ptr);
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
        public void ImportKey(string value, Certificate certificate, string password)
        {
            int hresult = CCadesSymmetricAlgorithm_import_key(_CCadesSymmetricAlgorithm, value, (IntPtr)certificate, password);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public string Encrypt(string value, bool isFinal)
        {
            IntPtr ptr = default;
            try
            {
                int arg_isFinal = Convert.ToInt32(isFinal);
                int hresult = CCadesSymmetricAlgorithm_encrypt(_CCadesSymmetricAlgorithm, value, arg_isFinal, ref ptr);
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
        public string Decrypt(string value, bool isFinal)
        {
            IntPtr ptr = default;
            try
            {
                int arg_isFinal = Convert.ToInt32(isFinal);
                int hresult = CCadesSymmetricAlgorithm_decrypt(_CCadesSymmetricAlgorithm, value, arg_isFinal, ref ptr);
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
        public bool LegacyPluginSymmetricExport
        {
            set
            {
                int piValue = Convert.ToInt32(value);
                int hresult = CCadesSymmetricAlgorithm_put_legacy_plugin_symmetric_export(_CCadesSymmetricAlgorithm, piValue);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
    }
}
