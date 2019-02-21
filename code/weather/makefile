CXXFLAGS=-g -std=c++14
CC=$(CXX)
INCS=$(shell ls *.h)

weather: weather.cpp

weather_leaks: weather_leaks.cpp

repo:
	-git commit -a 
	git push origin master

nocrud:
	-rm *~
	-rm .*swp
