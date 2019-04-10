#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([siloutil], [1.0], [n.donocik@tu-bs.de])
AC_CONFIG_FILES([Makefile 
  po/Makefile.in 
  src/Makefile
])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.19.8])

AC_PROG_MAKE_SET
AM_PROG_AR
AC_PROG_CXX
AC_LANG(C++)

CPPFLAGS="$CPPFLAGS -fPIC"

########################### PYTHON ############################################

AC_ARG_WITH(python3, [  --with-python3=INC,BIN     Use to specify a non-standard location for python])
if test "$with_python3" = no; then
    PY_INCDIR=""
    PY_BINDIR=""
    AC_MSG_ERROR(You need to have python for this)
elif test -n "$with_python3" && test "$with_python3" != yes; then
    PY_INCDIR="`echo $with_python3 |cut -f1 -d,`"
    PY_BINDIR="`echo $with_python3 | cut -f2 -d, -s`"
    CPPFLAGS="$CPPFLAGS -I$PY_INCDIR"
fi

AC_CHECK_HEADER([pyconfig.h], [], [AC_MSG_ERROR([Cannot find pyconfig.h])])

########################### Boost Python ######################################

AC_ARG_WITH(boost_python, [  --with-boost_python=INC,LIB     Use to specify a non-standard location for boost_python])
if test "$with_boost_python" = no; then
    PYBOOST_INCDIR=""
    PYBOOST_LIBDIR=""
    AC_MSG_ERROR(You need to have boost_python for this)
elif test -n "$with_boost_python" && test "$with_boost_python" != yes; then
    PYBOOST_INCDIR="`echo $with_boost_python |cut -f1 -d,`"
    # AC_MSG_ERROR( $PYBOOST_INCDIR )
    if test ! -f $PYBOOST_INCDIR/boost/python.hpp; then
        AC_MSG_ERROR(problem with directory specified for boost_python includes)
    fi
    PYBOOST_LIBDIR="`echo $with_boost_python | cut -f2 -d, -s`"
    if test ! -f $PYBOOST_LIBDIR/libboost_python37.a; then
        AC_MSG_ERROR(problem with directory specified for boost_python libs)
    fi
    CPPFLAGS="$CPPFLAGS -I$PYBOOST_INCDIR"
    LDFLAGS="$LDFLAGS -L$PYBOOST_LIBDIR"
    LIBS="$LIBS -lboost_python37"
fi

CPPFLAGS="$CPPFLAGS -I/home/niklas/Dokumente/siloutil-org/python/include/python3.7m"

 AC_SEARCH_LIBS([main], [boost_python37], [], [
  AC_MSG_ERROR([unable to find boost python])
])

########################### SILO #############################################

AC_ARG_WITH(silo, [  --with-silo=INC,LIB     Use to specify a non-standard location for silo])
if test "$with_silo" = no; then
    SILO_INCDIR=""
    SILO_LIBDIR=""
    AC_MSG_ERROR(You need to have silo for this)
elif test -n "$with_silo" && test "$with_silo" != yes; then
    SILO_INCDIR="`echo $with_silo |cut -f1 -d,`"
    if test ! -f $SILO_INCDIR/silo.h; then
        AC_MSG_ERROR(problem with directory specified for silo includes)
    fi
    SILO_LIBDIR="`echo $with_silo | cut -f2 -d, -s`"
    if test ! -f $SILO_LIBDIR/libsiloh5.a; then
        AC_MSG_ERROR(problem with directory specified for silo libs)
    fi
    CPPFLAGS="$CPPFLAGS -I$SILO_INCDIR"
    LDFLAGS="$LDFLAGS -L$SILO_LIBDIR"
    LIBS="$LIBS -lsiloh5"
fi

 AC_SEARCH_LIBS([main], [siloh5], [], [
  AC_MSG_ERROR([unable to find silo library])
])

########################### HDF5 #############################################

AC_ARG_WITH(hdf5, [  --with-hdf5=INC,LIB     Use to specify a non-standard location for hdf5])
if test "$with_hdf5" = no; then
    HDF5_INCDIR=""
    HDF5_LIBDIR=""
    AC_MSG_ERROR(You need to have silo for this)
elif test -n "$with_silo" && test "$with_hdf5" != yes; then
    HDF5_INCDIR="`echo $with_hdf5 |cut -f1 -d,`"
    if test ! -f $HDF5_INCDIR/hdf5.h; then
        AC_MSG_ERROR(problem with directory specified for hdf5 includes)
    fi
    HDF5_LIBDIR="`echo $with_hdf5 | cut -f2 -d, -s`"
    if test ! -f $HDF5_LIBDIR/libhdf5.a; then
        AC_MSG_ERROR(problem with directory specified for silo libs)
    fi
    CPPFLAGS="$CPPFLAGS -I$HDF5_INCDIR"
    LDFLAGS="$LDFLAGS -L$HDF5_LIBDIR"
    LIBS="$LIBS -lhdf5"
fi

 AC_SEARCH_LIBS([main], [hdf5], [], [
  AC_MSG_ERROR([unable to find hdf5 library])
])


########################### ZLIB #############################################

AC_ARG_WITH(zlib, [  --with-zlib=INC,LIB     Use to specify a non-standard location for hdf5])
if test "$with_hdf5" = no; then
    ZLIB_INCDIR=""
    ZLIB_LIBDIR=""
    AC_MSG_ERROR(You need to have silo for this)
elif test -n "$with_zlib" && test "$with_zlib" != yes; then
    ZLIB_INCDIR="`echo $with_zlib |cut -f1 -d,`"
    if test ! -f $ZLIB_INCDIR/zlib.h; then
        AC_MSG_ERROR(problem with directory specified for hdf5 includes)
    fi
    ZLIB_LIBDIR="`echo $with_zlib | cut -f2 -d, -s`"
    if test ! -f $ZLIB_LIBDIR/libz.a; then
        AC_MSG_ERROR(problem with directory specified for silo libs)
    fi
    CPPFLAGS="$CPPFLAGS -I$ZLIB_INCDIR"
    LDFLAGS="$LDFLAGS -L$ZLIB_LIBDIR"
    LIBS="$LIBS -lz"
fi

 AC_SEARCH_LIBS([main], [z], [], [
  AC_MSG_ERROR([unable to find lz library])
])

###########################################################################

LT_PREREQ([2.2])
LT_INIT([shared disable-static])

AC_OUTPUT
