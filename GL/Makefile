#
# Makefile for GLee library
#

CC = gcc

RM = rm -f # Linux
#RM = del # Windows

# Fix this to your lcgtk home directory

LCGTK_HOME = $(HOME)/lcgtk

# Determine where to put the output library

OUTPUT_LIB = $(LCGTK_HOME)/lib

CXXFLAGS = -Wall -Wno-deprecated

#-----------------------------------------------------------

libGLee.a: GLee.o
	ar -rs $(OUTPUT_LIB)/libGLee.a GLee.o
	rm -f GLee.o

GLee.o: GLee.c GLee.h
	$(CC) -o GLee.o -c $(CXXFLAGS) GLee.c

clean:
	$(RM) $(OUTPUT_LIB)/libGLee.a *.o *~
