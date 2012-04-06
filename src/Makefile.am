## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(datadir)/system_config_server/ui
ui_DATA = GTKBuilderResources/AboutWindow.glade \
	GTKBuilderResources/Main.glade


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(SYSTEM_CONFIG_SERVER_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = system_config_server

system_config_server_SOURCES = \
	main.cc \
	ModuleSubsystem/ServiceModuleMain.h \
	ModuleSubsystem/ServiceModuleMain.cc \
	ViewControllers/GTKBuilderViewController.cc \
	ViewControllers/GTKBuilderViewController.h \
	ViewControllers/AboutWindowViewController/AboutWindowViewController.cc \
	ViewControllers/AboutWindowViewController/AboutWindowViewController.h

system_config_server_LDFLAGS = 

system_config_server_LDADD = $(SYSTEM_CONFIG_SERVER_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/system_config_server

