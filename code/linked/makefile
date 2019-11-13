CXXFLAGS=-g -std=c++14 -Wall -pedantic
CC=$(CXX)
INCS=$(shell ls *.h)

FORCE:

test_linked: test_linked.cpp linked.cpp 

linked0: linked0.cpp

tests: test_linked linked0
	./test_linked
	./linked0

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	rm *~
