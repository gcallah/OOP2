
CXXFLAGS=-g -std=c++17 -Wall -pedantic 
# just run pre-processor:
# CXXFLAGS=-E -g -std=c++17 -Wall -pedantic 
CC=$(CXX)
INCS=$(shell ls *.h)

baseX: baseX.cpp 

towers: towers.cpp


tests: baseX # towers
	./baseX
# ./towers

prod: tests
	-git commit -a 
	git pull origin master
	git push origin master

nocrud:
	rm *~
