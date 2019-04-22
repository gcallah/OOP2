CXXFLAGS=-g -std=c++14
CC=$(CXX)
INCS=$(shell ls *.h)

FORCE:

test_linked: test_linked.cpp linked.cpp 

tests: FORCE
	test_linked

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	rm *~
