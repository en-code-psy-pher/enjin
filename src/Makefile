CXXFLAGS = -Og -Wall
BUILDDIR = ../build
LIBDIR = /libs/

main.o: main.cpp
	@echo "compiling with $(CXX)"
	$(CXX) -L$(LIBDIR) $(CXXFLAGS) main.cpp -o $(BUILDDIR)/main.o

.PHONY: clean

clean:
	@echo "cleaning build directory"
	@rm -rf ../build/*
