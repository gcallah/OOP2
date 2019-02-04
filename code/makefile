CXXFLAGS=-g -std=c++11
CC=$(CXX)
INCS=$(shell ls *.h)

complex: complex.cpp 

funcs: funcs.cpp 

hello: hello.cpp 

hello_nm: hello_nm.cpp 

mean: mean.cpp 

repo:
	-git commit -a 
	git push origin master

nocrud:
	rm *~
