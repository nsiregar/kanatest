AUTOMAKE_OPTIONS = -Wno-portability
ISREPO := "$(shell git rev-parse --is-inside-work-tree 2> /dev/null)"
REVISION := "$(shell git rev-parse --short HEAD 2>/dev/null)"
VERSION_MAJOR := $(shell echo $(VERSION) | awk -F "." '{print $$1}')
VERSION_MINOR := $(shell echo $(VERSION) | awk -F "." '{print $$2}')
VERSION_MICRO := $(shell echo $(VERSION) | awk -F "." '{print $$3}')

if !MAEMO
AM_CPPFLAGS = -DLOCALEDIR=\"$(datadir)/locale\" @GTK_CFLAGS@ @XML_CPPFLAGS@ \
			  -DREVISION=$(REVISION) \
			  -DVERSION_MAJOR=\"$(VERSION_MAJOR)\" -DVERSION_MINOR=\"$(VERSION_MINOR)\" -DVERSION_MICRO=\"$(VERSION_MICRO)\"

AM_CFLAGS = @CFLAGS@
			
bin_PROGRAMS = kanatest
kanatest_SOURCES = about.c about.h \
				   chart.c chart.h \
				   graphics.h \
				   gui.c gui.h \
				   gui_utils.c gui_utils.h \
				   i18n.h \
				   main.c main.h \
				   options.c options.h \
				   prefs.c prefs.h \
				   stats.c stats.h \
				   stock_icons.c stock_icons.h stock_icons_data.h \
				   test.c test.h 

kanatest_LDADD = $(LIBINTL) @GTK_LIBS@ -lm @XML_LIBS@

else

bin_PROGRAMS = kanatest

kanatest_LDADD = $(gtk_LIBS) $(xml_LIBS) $(HILDON_LIBS) $(OSSO_LIBS)

kanatest_CFLAGS= $(gtk_CFLAGS) $(xml_CFLAGS) $(HILDON_CFLAGS) $(OSSO_CFLAGS)

kanatest_SOURCES = about.c about.h \
				   chart.c chart.h \
				   graphics.h \
				   gui.c gui.h \
				   gui_utils.c gui_utils.h \
				   i18n.h \
				   main.c main.h \
				   options.c options.h \
				   prefs.c prefs.h \
				   stats.c stats.h \
				   stock_icons.c stock_icons.h stock_icons_data.h \
				   test.c test.h 

endif
