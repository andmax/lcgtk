#
# Makefile for the entire LCG Tool Kit repository 'lcgtk/'
#
#  'lcgtk/' is a repository of OpenGL and Geometry source
#   codes for LCG (www.lcg.ufrj.br) students. 
#

# List of projects inside the LCG Tool Kit

# The subdirectories 'errHandle/' and 'geomTypes/' are
#   include-only projects
# The subdirectory 'lal/' is a under-construction project
# The GLSL Kernel and GLee libraries are built separately
#   by this global Makefile, to built them together go to
#   the 'glslKernel/' subdirectory

PROJECTS = lib/libglslKernel.a lib/libGLee.a 

#-----------------------------------------------------------

all: $(PROJECTS)

lib/libGLee.a:		GL/Makefile
			make -C GL/ -f Makefile

lib/libglslKernel.a:	glslKernel/Makefile
			make -C glslKernel/ -f Makefile

#lal:	lal/Makefile
#	cd lal/
#	make -f Makefile
#	cd ../

clean:
	make -C GL/ -f Makefile clean
	make -C glslKernel/ -f Makefile clean
	make -C lal/ -f Makefile clean
