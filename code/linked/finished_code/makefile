CXXFLAGS=-g -std=c++14 -Wall -pedantic
CC=$(CXX)
INCS=$(shell ls *.h)

FORCE:

test_linked: test_linked.cpp linked.cpp 

tests: test_linked
	./test_linked

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	rm *~
