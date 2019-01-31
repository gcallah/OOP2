CXXFLAGS=-g -std=c++11
CC=$(CXX)
INCS=$(shell ls *.h)

funcs: funcs.cpp 

hello: hello.cpp 

hello_nm: hello_nm.cpp 

repo:
	./all_tests.sh
	-git commit -a 
	git push origin master
