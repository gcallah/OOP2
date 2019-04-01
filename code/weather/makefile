CXXFLAGS=-g -std=c++14
CC=$(CXX)
LINTFLAGS=--filter=-whitespace/braces,-build/namespaces,-runtime/references
INCS=$(shell ls *.h)
CPP_FILES=weather.cpp image.cpp date.cpp reading.cpp

weather_pre: weather.cpp
	clang --preprocess -std=c++14 weather.cpp

weather_comp: weather.cpp
	clang --compile -std=c++14 weather.cpp

date_test: date.cpp date_test.cpp

image_test: image.cpp image_test.cpp

weather: $(CPP_FILES)

weather_leaks: weather_leaks.cpp

lint:
	cpplint $(LINTFLAGS) $(CPP_FILES)

repo: lint
	-git commit -a 
	git push origin master

nocrud:
	-rm *~
	-rm .*swp
