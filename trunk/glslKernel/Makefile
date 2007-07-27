#
# Makefile for glsl
#

CXX = g++

CFLAGS = -g -Wall -Wno-deprecated -D_NVIDIA_

#--------------------------------------------

glslKernel.o: glslKernel.h

.cc.o:
	$(CXX) -c $(CFLAGS) $<

clean:
	rm -f *.o *~
