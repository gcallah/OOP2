CXXFLAGS=-g -std=c++14
CC=$(CXX)
INCS=$(shell ls *.h)

FORCE:

test_linked: test_linked.cpp linked1.cpp 

tests: FORCE
	test_ll

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	rm *~
