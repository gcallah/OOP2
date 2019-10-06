CXXFLAGS=-g -std=c++17 -Wall -pedantic 
CC=$(CXX)
INCS=$(shell ls *.h)

FORCE:

# test_my_vec: test_my_vec.cpp my_vec.cpp 

tests: 

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	rm *~
