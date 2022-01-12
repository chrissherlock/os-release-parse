# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t; fill-column: 100 -*-

CXX = clang++ -std=c++17
DEBUG = -g
INCLUDES = -I./include
CXXFILES = src/main.cpp src/parser.cpp
CXXFLAGS = $(INCLUDES)
OBJ = $(CXXFILES:.cpp=.o)
CPPUNITOBJ = src/parser.cpp
EXECUTABLE = os-release-parse
CPPUNITLINKFLAGS = -lcppunit
CPPUNITTESTEXECUTABLE = runtests

build: $(CXXFILES)
	$(CXX) -o $(EXECUTABLE) $(CXXFILES) $(DEBUG)

test: qa/cppunit/tests.cpp $(OBJ)
	$(CXX) -o $(CPPUNITTESTEXECUTABLE) qa/cppunit/tests.cpp $(CPPUNITOBJ) $(CPPUNITLINKFLAGS) $(INCLUDES)
clean:
	rm -f *.o core $(EXECUTABLE) $(CPPUNITTESTEXECUTABLE)
	touch $(CXXFILES)

# vim: set noet sw=4 ts=4:
