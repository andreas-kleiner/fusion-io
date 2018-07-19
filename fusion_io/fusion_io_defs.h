#ifndef FUSION_IO_DEFS_H
#define FUSION_IO_DEFS_H

#ifdef FORTRAN
#define FIO_DEFINE_INT(x, y) integer, parameter :: x = y
#define INDEX_OFFSET 1
#elif defined(PYTHON)
#undef FIO_DEFINE_INT
#define FIO_DEFINE_INT(x, y) PyDict_SetItemString(PYTHON_DICT, #x, PyInt_FromLong(y));
#else
#define FIO_DEFINE_INT(x, y) const int x = y;
#define FIO_IS_STR_OPT(x)    ((x)>FIO_STR_OPT_START && (x)<FIO_STR_OPT_END)
#define FIO_IS_INT_OPT(x)    ((x)>FIO_INT_OPT_START && (x)<FIO_INT_OPT_END)
#define FIO_IS_REAL_OPT(x)   ((x)>FIO_REAL_OPT_START && (x)<FIO_REAL_OPT_END)
#define INDEX_OFFSET 0
#endif
#define COMMENT(x) 

COMMENT(     sources     )
FIO_DEFINE_INT(FIO_GATO_SOURCE,       1)
FIO_DEFINE_INT(FIO_GEQDSK_SOURCE,     2)
FIO_DEFINE_INT(FIO_M3DC1_SOURCE,      3)
FIO_DEFINE_INT(FIO_MARS_SOURCE,       4)
FIO_DEFINE_INT(FIO_NIMROD_SOURCE,     5)

COMMENT(      scalar fields      )
FIO_DEFINE_INT(FIO_ALPHA,             1)
FIO_DEFINE_INT(FIO_SCALAR_POTENTIAL,  2)
FIO_DEFINE_INT(FIO_TOTAL_PRESSURE,    3)

COMMENT(      species-dependent scalar fields      )
FIO_DEFINE_INT(FIO_PRESSURE,          101)
FIO_DEFINE_INT(FIO_DENSITY,           102)
FIO_DEFINE_INT(FIO_TEMPERATURE,       103)

COMMENT(      vector fields      )
FIO_DEFINE_INT(FIO_ELECTRIC_FIELD,    1001)
FIO_DEFINE_INT(FIO_VECTOR_POTENTIAL,  1002)
FIO_DEFINE_INT(FIO_MAGNETIC_FIELD,    1003)
FIO_DEFINE_INT(FIO_CURRENT_DENSITY,   1004)
FIO_DEFINE_INT(FIO_FLUID_VELOCITY,    1005)

COMMENT(      species-dependent vector fields      )
FIO_DEFINE_INT(FIO_VELOCITY,          1101)

COMMENT(      tensor fields      )
FIO_DEFINE_INT(FIO_GRAD_VECTOR_POTENTIAL, 2001)

COMMENT(      series             )
FIO_DEFINE_INT(FIO_MAGAXIS_PSI,       3001)
FIO_DEFINE_INT(FIO_LCFS_PSI,          3002)
FIO_DEFINE_INT(FIO_MAGAXIS_R,         3003)
FIO_DEFINE_INT(FIO_MAGAXIS_Z,         3004)

COMMENT(      integer parameters         )
FIO_DEFINE_INT(FIO_NUM_TIMESLICES,    4001)
FIO_DEFINE_INT(FIO_GEOMETRY,          4002)

COMMENT(      real parameters         )
FIO_DEFINE_INT(FIO_PERIOD,            5001)

COMMENT(      real field parameters   )
FIO_DEFINE_INT(FIO_TIME,              7001)

COMMENT(      coordinate system             )
FIO_DEFINE_INT(FIO_CARTESIAN,   0)
FIO_DEFINE_INT(FIO_CYLINDRICAL, 1)

COMMENT(      field options (integers)      )
FIO_DEFINE_INT(FIO_INT_OPT_START,     0)
FIO_DEFINE_INT(FIO_TIMESLICE,         1)
FIO_DEFINE_INT(FIO_PART,              2)
FIO_DEFINE_INT(FIO_SPECIES,           3)
FIO_DEFINE_INT(FIO_INT_OPT_END,       4)

COMMENT(      possible options for FIO_PART      )
FIO_DEFINE_INT(FIO_TOTAL,             0)
FIO_DEFINE_INT(FIO_PERTURBED_ONLY,    1)
FIO_DEFINE_INT(FIO_EQUILIBRIUM_ONLY,  2)

COMMENT(      field options (reals)      )
FIO_DEFINE_INT(FIO_REAL_OPT_START,    100)
FIO_DEFINE_INT(FIO_LINEAR_SCALE,      101)
FIO_DEFINE_INT(FIO_PHASE,             102)
FIO_DEFINE_INT(FIO_REAL_OPT_END,      103)

COMMENT(      field options (strings)      )
FIO_DEFINE_INT(FIO_STR_OPT_START,     10000)
FIO_DEFINE_INT(FIO_STR_OPT_END,       10000)

COMMENT(      field operations      )
FIO_DEFINE_INT(FIO_ADD,               1)
FIO_DEFINE_INT(FIO_MULTIPLY,          2)
FIO_DEFINE_INT(FIO_DIVIDE,            3)
FIO_DEFINE_INT(FIO_DOT_PRODUCT,       4)

COMMENT(      error messages      )
FIO_DEFINE_INT(FIO_SUCCESS,           0)
FIO_DEFINE_INT(FIO_UNSUPPORTED,       10001)
FIO_DEFINE_INT(FIO_OUT_OF_BOUNDS,     10002)
FIO_DEFINE_INT(FIO_FILE_ERROR,        10003)
FIO_DEFINE_INT(FIO_BAD_DIMENSIONS,    10004)
FIO_DEFINE_INT(FIO_BAD_SPECIES,       10005)
FIO_DEFINE_INT(FIO_NO_DATA,           10006)

COMMENT(      vector components      )
FIO_DEFINE_INT(FIO_R, 0+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_PHI, 1+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_Z, 2+INDEX_OFFSET)

FIO_DEFINE_INT(FIO_DR, 0+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DPHI, 1+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DZ, 2+INDEX_OFFSET)

FIO_DEFINE_INT(FIO_DR_R, 0+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DR_PHI, 1+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DR_Z, 2+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DPHI_R, 3+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DPHI_PHI, 4+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DPHI_Z, 5+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DZ_R, 6+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DZ_PHI, 7+INDEX_OFFSET)
FIO_DEFINE_INT(FIO_DZ_Z, 8+INDEX_OFFSET)

COMMENT(      species      )

#define FIO_MAKE_SPECIES(m, p, e)     e + p*256 + (m-p)*65536
#ifdef FORTRAN
#define FIO_GET_N(x)                 iand(x, 16711680)
#define FIO_GET_P(x)                 iand(x, 65280)
#define FIO_GET_E(x)                 iand(x, 255)
#else
#define FIO_GET_N(x)                 x & 16711680
#define FIO_GET_P(x)                 x & 65280
#define FIO_GET_E(x)                 x & 255
#endif
#define FIO_GET_M(x)                 FIO_GET_N(x) + FIO_GET_P(x)
FIO_DEFINE_INT(FIO_MAIN_ION, -1)
FIO_DEFINE_INT(FIO_ELECTRON, FIO_MAKE_SPECIES(0, 0, 1))
FIO_DEFINE_INT(FIO_H_0,      FIO_MAKE_SPECIES(1, 1, 1))
FIO_DEFINE_INT(FIO_H_1,      FIO_MAKE_SPECIES(1, 1, 0))
FIO_DEFINE_INT(FIO_D_0,      FIO_MAKE_SPECIES(2, 1, 1))
FIO_DEFINE_INT(FIO_D_1,      FIO_MAKE_SPECIES(2, 1, 0))
FIO_DEFINE_INT(FIO_T_0,      FIO_MAKE_SPECIES(3, 1, 1))
FIO_DEFINE_INT(FIO_T_1,      FIO_MAKE_SPECIES(3, 1, 0))
FIO_DEFINE_INT(FIO_He3_0,    FIO_MAKE_SPECIES(3, 2, 2))
FIO_DEFINE_INT(FIO_He3_1,    FIO_MAKE_SPECIES(3, 2, 1))
FIO_DEFINE_INT(FIO_He3_2,    FIO_MAKE_SPECIES(3, 2, 0))
FIO_DEFINE_INT(FIO_He4_0,    FIO_MAKE_SPECIES(4, 2, 2))
FIO_DEFINE_INT(FIO_He4_1,    FIO_MAKE_SPECIES(4, 2, 1))
FIO_DEFINE_INT(FIO_He4_2,    FIO_MAKE_SPECIES(4, 2, 0))
FIO_DEFINE_INT(FIO_Li7_0,    FIO_MAKE_SPECIES(7, 3, 3))
FIO_DEFINE_INT(FIO_Li7_1,    FIO_MAKE_SPECIES(7, 3, 2))
FIO_DEFINE_INT(FIO_Li7_2,    FIO_MAKE_SPECIES(7, 3, 1))
FIO_DEFINE_INT(FIO_Li7_3,    FIO_MAKE_SPECIES(7, 3, 0))


#endif
