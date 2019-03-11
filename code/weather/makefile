CXXFLAGS=-g -std=c++14
CC=$(CXX)
LINTFLAGS=--filter=-whitespace/braces,-build/namespaces
INCS=$(shell ls *.h)

weather_pre: weather.cpp
	clang --preprocess -std=c++14 weather.cpp

weather_comp: weather.cpp
	clang --compile -std=c++14 weather.cpp

weather: weather.cpp image.cpp

weather_leaks: weather_leaks.cpp

lint:
	cpplint $(LINTFLAGS) weather.cpp

repo: lint
	-git commit -a 
	git push origin master

nocrud:
	-rm *~
	-rm .*swp
