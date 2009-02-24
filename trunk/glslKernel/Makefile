#
# Makefile for glslKernel library
#

CXX = g++

RM = rm -f # Linux
#RM = del # Windows

# Enter the correct include directory where the GLee.h
# file is, or simply comment it (in case it is in the
# current directory)
INCLUDE = -I$(HOME)/lcgtk

CXXFLAGS = -Wall -Wno-deprecated $(INCLUDE)

# If you don't want to GLee to be joined with glslKernel
# comment the next line (to generate the GLee.o file just
# compile it using $ gcc -c GLee.c)

#GLee = GLee.o

#-----------------------------------------------------------

libglslKernel.a: glslKernel.o
	ar -rs libglslKernel.a glslKernel.o $(GLee)

glslKernel.o: glslKernel.cc glslKernel.h
	$(CXX) -o glslKernel.o -c $(CXXFLAGS) glslKernel.cc

clean:
	$(RM) *.a *.o *~

