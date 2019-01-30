CXXFLAGS=-g -std=c++11
CC=$(CXX)
INCS=$(shell ls *.h)

intro: intro.cpp 

repo:
	./all_tests.sh
	-git commit -a 
	git push origin master
