#---------------------------------------------------------------------#
# Executable program name
EXEC		=	main
#---------------------------------------------------------------------#

# compiler names:
CXX		= 	g++                     
CC		= 	gcc
C++		=	c++
RANLIB  	= 	ranlib

# flags for C++ compiler:

CFLAGS			= 	-p -g -Wall -Wno-deprecated -DLINUX # -O2
CXXFLAGS 		= 	-g -Wall -Wno-deprecated -DLINUX 
DEFFLAGS		=	 
				
INCFLAGS 		= 	

MATLIB          = -lm
GLLIBS          = -lGL -lGLU
GLUTLIB         = -lglut
#GLUILIB 	= -lglui
X11LIB		= -lX11 -lXext -lXmu -lXi

#---------------------------------------------------------------------#
#                    compiler flags
#---------------------------------------------------------------------#

CXXFLAGS = \
           -I../../include \
           $(TESTSUITE_CXXFLAGS) \
           $(EXTRA_FLAGS) \
           $(LONG_NAME_PROBLEM_CXXFLAGS)

#---------------------------------------------------------------------#
#                    linker flags
#---------------------------------------------------------------------#

LIBPATH = -L/usr/X11R6/lib \
          $(TESTSUITE_LIBPATH) \

          


LDFLAGS = \
       	$(TESTSUITE_LDFLAGS) \
       	$(LONG_NAME_PROBLEM_LDFLAGS) \
	  	$(X11LIB) \
		$(GLUILIB) \
		$(GLUTLIB) \
		$(GLLIBS) 

OBJECTS_DIR   = .obj/
        

SRCFILES	= 	main.cpp \
 	Color.cpp \
    Quaternion.cpp \
    Math.cpp \
    Point2.cpp \
    Point3.cpp \
    Vector3.cpp \
    Vector4.cpp \
    Matrix3x3.cpp \
    Matrix4x4.cpp 
    

OBJFILES	= .obj/main.o \
		.obj/Quaternion.o \
		.obj/Math.o \
		.obj/Point2.o \
		.obj/Point3.o \
		.obj/Vector2.o \
		.obj/Vector3.o \
		.obj/Vector4.o \
		.obj/Matrix3x3.o \
		.obj/Matrix4x4.o 
		

.obj/main.o: main.cpp \
		Point2.hpp \
		Point2.inline.hpp \
		Point3.hpp \
		Point3.inline.hpp \
		Vector3.hpp \
		Vector3.inline.hpp \
		Vector4.hpp \
		Vector4.inline.hpp \
		BoundingBox3.hpp \
		Color.hpp \
		EigenSystem.hpp \
		Matrix3x3.hpp \
		Matrix3x3.inline.hpp \
		Matrix4x4.hpp \
		Matrix4x4.inline.hpp \
		Math.hpp \
		Quaternion.hpp \
		Quaternion.inline.hpp 		
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp


.obj/Quaternion.o: Quaternion.cpp Quaternion.hpp \
		Vector3.hpp \
		Vector3.inline.hpp \
		Matrix3x3.hpp \
		Point3.hpp \
		Point3.inline.hpp \
		Matrix3x3.inline.hpp \
		Matrix4x4.hpp \
		Math.hpp \
		Vector4.hpp \
		Vector4.inline.hpp \
		Matrix4x4.inline.hpp \
		Quaternion.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Quaternion.o Quaternion.cpp


.obj/Math.o: Math.cpp Math.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Math.o Math.cpp

.obj/Vector3.o: Vector3.cpp Vector3.hpp \
		Vector3.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Vector3.o Vector3.cpp

.obj/Point2.o: Point2.cpp Point2.hpp \
		Math.hpp \
		Vector2.hpp \
		Vector2.inline.hpp \
		Point2.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Point2.o Point2.cpp

.obj/Vector4.o: Vector4.cpp Vector4.hpp \
		Vector3.hpp \
		Vector3.inline.hpp \
		Vector4.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Vector4.o Vector4.cpp

.obj/Matrix3x3.o: Matrix3x3.cpp Matrix3x3.hpp \
		Vector3.hpp \
		Vector3.inline.hpp \
		Point3.hpp \
		Point3.inline.hpp \
		Matrix3x3.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Matrix3x3.o Matrix3x3.cpp

.obj/Matrix4x4.o: Matrix4x4.cpp Matrix4x4.hpp \
		Math.hpp \
		Vector4.hpp \
		Vector3.hpp \
		Vector3.inline.hpp \
		Vector4.inline.hpp \
		Matrix4x4.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Matrix4x4.o Matrix4x4.cpp

.obj/Point3.o: Point3.cpp Point3.hpp \
		Vector3.hpp \
		Vector3.inline.hpp \
		Point3.inline.hpp
	$(CXX) -c $(CXXFLAGS)  -o .obj/Point3.o Point3.cpp

.obj/Vector2.o: Vector2.cpp Vector2.hpp \
		Vector2.inline.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Vector2.o Vector2.cpp

#---------------------------------------------------------------------#
#                    target entries
#---------------------------------------------------------------------#

all:	$(EXEC) 

$(EXEC):	$(OBJFILES)
		@echo "Linking ...."
		$(CXX) -o $@ $^ $(LIBPATH) $(LDFLAGS)
		
	
.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS)  -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS)  -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS)  -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS)  -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS)  -o "$@" "$<"
clean: 
	@echo "Clearing ..."
	rm -f .obj/*.o core* *~ $(EXEC)


