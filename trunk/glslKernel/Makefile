#
# Makefile for glslKernel library
#

CC = gcc
CXX = g++

#RM = rm -f
RM = del

CFLAGS = -Wall
CXXFLAGS = -Wall -Wno-deprecated

#--------------------------------------------

libglslKernel.a: glslKernel.o
	ar -rs libglslKernel.a glslKernel.o

glslKernel.o: glslKernel.cc glslKernel.h
	$(CXX) -o glslKernel.o -c $(CXXFLAGS) glslKernel.cc

clean:
	$(RM) *.a *.o
