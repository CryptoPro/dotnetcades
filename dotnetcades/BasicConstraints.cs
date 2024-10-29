using System;
using System.Runtime.InteropServices;

namespace dotnetcades
{
    public class BasicConstraints : IDisposable
    {
        IntPtr _CCadesBasicConstraints = IntPtr.Zero;

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_create(ref IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_destroy(IntPtr self);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_get_is_present(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_put_is_present(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_get_is_critical(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_put_is_critical(IntPtr self, int value);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_get_is_certificate_authority(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_get_is_path_len_constraint_present(IntPtr self, ref int result);

        [DllImport("../ccades/libccades", CharSet = CharSet.Ansi)]
        public static extern int CCadesBasicConstraints_get_path_len_constraint(IntPtr self, ref int result);

        public BasicConstraints() 
        {
            int hresult = CCadesBasicConstraints_create(ref _CCadesBasicConstraints);
            if (hresult != 0)
            {
                throw new Exception(NC.GetErrorMessage(hresult));
            }
        }
        public BasicConstraints(IntPtr m)
        {
            _CCadesBasicConstraints = m;
        }
        public static explicit operator IntPtr(BasicConstraints value)
        {
            return value._CCadesBasicConstraints;
        }
        public void Dispose()
        {
            int hresult = CCadesBasicConstraints_destroy(_CCadesBasicConstraints);
            if (hresult != 0)
            {
                Console.WriteLine($"BasicConstraints.Dispose() failed: {hresult}");
            }
        }

        public bool IsPresent
        {
            get
            {
                int result = default;
                int hresult = CCadesBasicConstraints_get_is_present(_CCadesBasicConstraints, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }

            set
            {
                int piValue = Convert.ToInt32(value);
                int hresult = CCadesBasicConstraints_put_is_present(_CCadesBasicConstraints, piValue);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public bool IsCritical
        {
            get
            {
                int result = default;
                int hresult = CCadesBasicConstraints_get_is_critical(_CCadesBasicConstraints, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }

            set
            {
                int piValue = Convert.ToInt32(value);
                int hresult = CCadesBasicConstraints_put_is_critical(_CCadesBasicConstraints, piValue);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
            }
        }
        public bool IsCertificateAuthority
        {
            get
            {
                int result = default;
                int hresult = CCadesBasicConstraints_get_is_certificate_authority(_CCadesBasicConstraints, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public bool IsPathLenConstraintPresent
        {
            get
            {
                int result = default;
                int hresult = CCadesBasicConstraints_get_is_path_len_constraint_present(_CCadesBasicConstraints, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result != 0;
            }
        }
        public int PathLenConstraint
        {
            get
            {
                int result = default;
                int hresult = CCadesBasicConstraints_get_path_len_constraint(_CCadesBasicConstraints, ref result);
                if (hresult != 0)
                {
                    throw new Exception(NC.GetErrorMessage(hresult));
                }
                return result;
            }
        }
    }
}
