# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t; fill-column: 100 -*-

CC = clang++ -std=c++17
DEBUG = -g
CXXFILES = src/main.cxx
INCLUDE	= include 
EXECUTABLE = os-release-parse

build: $(CXXFILES)
	$(CC) -o $(EXECUTABLE) $(CXXFILES) -I$(INCLUDE) $(DEBUG)

clean:
	rm -f *.o core $(EXECUTABLE)
	touch $(CXXFILES)

# vim: set noet sw=4 ts=4:
