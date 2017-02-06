# Makefile for Assignment 2	#
# Noriaki Nakano			#
# nnakano@ucsc.edu			#
# 1418185					#
######################################################################################
# Makefile CMPS109 assignment 2
# prog1: compiles problem1 (institute.exe)
# prog2: compiles problem2 (scanner.exe)
# prog3: (attemps) to compile problem 3 (problem with inheritance) (MAX_Heap.exe)
# all: compiles all problems
# clean: removes exe and object files 
# check1: checks for memory leaks for problem 1 
# check2: checks for memory leaks for problem 2 
# check3: checks for memory leaks for problem 3 
######################################################################################

CXX	=	g++
FLAGS	=	-std=gnu++0x	-Wall 
SOURCES	=	institute.cpp	classroom.cpp	student.cpp	PointerList.cpp	
SOURCES2	=	scanner.cpp	product_type.cpp	product.cpp	PointerList.cpp
SOURCES3	=	MAX_Heap.cpp	Heap.cpp
OBJECTS	=	$(SOURCES:.cpp=.o)
OBJECTS2	=	$(SOURCES2:.cpp=.o)
OBJECTS3	=	$(SOURCES3:.cpp=.o)
OBJECTSS	=	$(OBJECTS)	$(OBJECTS2)	$(OBJECTS3)
EXEBIN	=	institute 
EXEBIN2	=	scanner
EXEBIN3	=	MAX_Heap
EXEBINS = $(EXEBIN) $(EXEBIN2) $(EXEBIN3)

######################################################################################

all:	prog1	prog2	prog3

prog1:	$(SOURCES)
	$(CXX)	$(FLAGS)	-o	$(EXEBIN)	$(SOURCES)	-g

prog2:	$(SOURCES2)
	$(CXX)	$(FLAGS)	-o	$(EXEBIN2)	$(SOURCES2)	-g

prog3:	$(SOURCES3)
	$(CXX)	$(FLAGS)	-o	$(EXEBIN3)	$(SOURCES3)	-g
	
clean:
	rm	-f	$(EXEBINS) $(OBJECTSS)

check1:
	valgrind	--leak-check=full	-v $(EXEBIN)

check2:
	valgrind	--leak-check=full	-v $(EXEBIN2)
	
check3:
	valgrind	--leak-check=full	-v $(EXEBIN3)
	
######################################################################################

