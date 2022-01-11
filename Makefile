CC	= clang++ -std=c++17
DEBUG	= -g
CXXFILES	= main.cxx
INCLUDE	= INCLUDE
EXECUTABLE	= os-release-parse

build: $(CXXFILES)
	$(CC) -o $(EXECUTABLE) $(CXXFILES) -I$(INCLUDE) $(DEBUG)

clean:
	rm -f *.o core $(EXECUTABLE)
	touch $(CXXFILES)
