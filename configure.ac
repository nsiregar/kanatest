#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([Kanatest], [0.4.10], [pasp@users.sf.net])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/about.c])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

AM_PATH_GTK_3_0(3.10.0,,
    AC_MSG_ERROR([GTK+ not found or too old (version < 3.10)]))

AM_PATH_XML2(2.0.0,,
    AC_MSG_ERROR([You do not appear to have libxml2 installed.]))

AC_CHECK_PROG([var], [xml2-config], [yes], [no])
if test ! "$var" = "yes"; then
    AC_MSG_ERROR(You do not appear to have xml2-config installed.)
fi

AC_ARG_ENABLE(
    debug,
    [  --enable-debug=yes,no   compile with debugging support (default: no)],
    debug="$enableval",
    debug="no")
if test "x$debug" = "xyes"; then
    BUILD_CFLAGS="-rdynamic -ggdb -g -O0"
    AC_DEFINE([DEBUG_BUILD], [1], [Defined if doing a debug build])
fi

dnl CFLAGS="$BUILD_CFLAGS -Wall $PLATFORM_CFLAGS -D_GNU_SOURCE"
dnl CXXFLAGS="$CFLAGS"

CFLAGS=${CFLAGS:="$BUILD_CFLAGS -Wall $PLATFORM_CFLAGS -D_GNU_SOURCE"}
CXXFLAGS=${CXXFLAGS:="$CFLAGS"}
CPPFLAGS=""
LIBS=""

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([libintl.h stdlib.h string.h sys/time.h unistd.h locale.h limits.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_TIME
AC_STRUCT_TM

# Checks for library functions.
AC_FUNC_STAT
AC_CHECK_FUNCS([gettimeofday strrchr])

AC_ARG_ENABLE(maemo,
  AS_HELP_STRING([--enable-maemo],[enable Maemo-specific features]),
  [],
  enable_maemo=no)

AM_CONDITIONAL([MAEMO], [test x$enable_maemo = xyes])

if test x"$enable_maemo" = xyes; then

AC_DEFINE([MAEMO], [1], [Maemo platform support])

# Hildon library dependencies
PKG_CHECK_MODULES(HILDON, hildon-1 hildon-fm-2 conbtdialogs)
AC_SUBST(HILDON_LIBS)
AC_SUBST(HILDON_CFLAGS)

# Only used for the .service file path
PKG_CHECK_MODULES(DBUS, dbus-glib-1 >= 0.60)

# OSSO application framework dependencies
PKG_CHECK_MODULES(OSSO, osso-af-settings >= 0.8.5 libosso >= 0.9.17 gnome-vfs-2.0 >= 2.8.4.11 gnome-vfs-module-2.0 >= 2.8.4.11)
AC_SUBST(OSSO_LIBS)
AC_SUBST(OSSO_CFLAGS)

# Application icon install directories
icon_26x26dir=$datadir/icons/hicolor/26x26/hildon
icon_40x40dir=$datadir/icons/hicolor/40x40/hildon
icon_scalabledir=$datadir/icons/hicolor/scalable/hildon

localedir=`$PKG_CONFIG osso-af-settings --variable=localedir`

# Localization-related
#AC_PROG_INTLTOOL([0.23])
GETTEXT_PACKAGE=kanatest
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED( GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Name of gettext package ])
ALL_LINGUAS="de es fi fr hu it pl pt ru"
AM_GLIB_GNU_GETTEXT
AC_SUBST(ALL_LINGUAS)
AC_SUBST(localedir)
AC_DEFINE_UNQUOTED(LOCALEDIR,"$localedir",[localedir])

desktopentrydir=`$PKG_CONFIG osso-af-settings --variable=desktopentrydir`
serviceentrydir=`$PKG_CONFIG osso-af-settings --variable=dbusservicedir`

AC_SUBST(serviceentrydir)
AC_SUBST(desktopentrydir)
AC_SUBST(icon_26x26dir)
AC_SUBST(icon_40x40dir)
AC_SUBST(icon_scalabledir)

fi

AC_CONFIG_FILES([ 
    Makefile
    src/Makefile
    po/Makefile
    data/Makefile
    data/icons/Makefile
    data/icons/16x16/Makefile
    data/icons/22x22/Makefile
    data/icons/24x24/Makefile
    data/icons/32x32/Makefile
    data/icons/48x48/Makefile
    data/icons/scalable/Makefile
    data/pixmaps/Makefile
])
AC_OUTPUT

echo "
Configuration:

    Maemo support:      $enable_maemo
    Debug enabled:      $debug
"
