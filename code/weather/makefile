CXXFLAGS=-g -std=c++14 -Wall -pedantic
# to turn off assertions, use this:
# CXXFLAGS=-g -std=c++14 -Wall -pedantic -DNDEBUG
CC=$(CXX)
LINTFLAGS=--filter=-whitespace/braces,-build/namespaces,-runtime/references
INCS=$(shell ls *.h)
CPP_FILES=weather.cpp image.cpp date.cpp reading.cpp rawdata.cpp

weather_pre: weather.cpp
	clang --preprocess -std=c++14 weather.cpp

weather_comp: weather.cpp
	clang --compile -std=c++14 weather.cpp

test_date: date.cpp test_date.cpp

test_image: image.cpp test_image.cpp

test_rawdata: rawdata.cpp test_rawdata.cpp

weather: $(CPP_FILES)

weather_leaks: weather_leaks.cpp

tests: test_date test_image test_rawdata
	./test_date
	./test_image
	./test_rawdata

lint:
	cpplint $(LINTFLAGS) $(CPP_FILES)

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	-rm *~
	-rm .*swp
