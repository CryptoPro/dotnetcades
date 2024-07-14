using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class Certificates : IDisposable
    {
        IntPtr _CCadesCertificates = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_get_item(IntPtr self, int value, ref IntPtr result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_get_count(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesCertificates_find_s(IntPtr self, int FindType, string Criteria, int ValidOnly, ref IntPtr result);


        public Certificates() 
        {
            int hresult = CCadesCertificates_create(ref _CCadesCertificates);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public Certificates(IntPtr m)
        {
            _CCadesCertificates = m;
        }
        public void Dispose()
        {
            int hresult = CCadesCertificates_destroy(_CCadesCertificates);
            if (hresult != 0)
            {
                Console.WriteLine($"Certificates.Dispose() failed: {hresult}");
            }
        }
        public Certificate Item(int value)
        {
            IntPtr ptr = IntPtr.Zero;
            int hresult = CCadesCertificates_get_item(_CCadesCertificates, value, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            Certificate result = new Certificate(ptr);
            return result;
        }
        public int Count
        {
            get
            {
                int result = 0;
                int hresult = CCadesCertificates_get_count(_CCadesCertificates, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
        // TODO: string only
        public Certificates Find(int FindType, string Criteria, bool ValidOnly = false)
        {
            IntPtr ptr = IntPtr.Zero;
            int iValidOnly = Convert.ToInt32(ValidOnly);
            int hresult = CCadesCertificates_find_s(_CCadesCertificates, FindType, Criteria, iValidOnly, ref ptr);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
            Certificates result = new Certificates(ptr);
            return result;

        }
    }
}



