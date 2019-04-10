ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"
lib_LTLIBRARIES	= libsiloutil.la
libsiloutil_la_SOURCES= helloworld.cpp gettext.h
libsiloutil_la_LDADD = $(LIBINTL)
AM_LDFLAGS = -shared -lboost_python37
