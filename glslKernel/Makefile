#
# Makefile for glslKernel library
#

CXX = g++

RM = rm -f # Linux
#RM = del # Windows

# Fix this to your lcgtk home directory

LCGTK_HOME = $(HOME)/lcgtk

# Determine where to put the output library

OUTPUT_LIB = $(LCGTK_HOME)/lib

# Enter the correct include directory where the GLee.h
# file is, or simply comment it (in case it is in the
# current directory)

INCLUDE = -I$(LCGTK_HOME)

CXXFLAGS = -Wall -Wno-deprecated $(INCLUDE)

# If you don't want to GLee to be joined with glslKernel
# comment the next line (to generate the GLee.o file just
# compile it using $ gcc -c GLee.c)

#GLee = GLee.o

#-----------------------------------------------------------

libglslKernel.a: glslKernel.o
	ar -rs $(OUTPUT_LIB)/libglslKernel.a glslKernel.o $(GLee)
	rm -f glslKernel.o

glslKernel.o: glslKernel.cc glslKernel.h
	$(CXX) -o glslKernel.o -c $(CXXFLAGS) glslKernel.cc

clean:
	$(RM) *.a *.o *~

