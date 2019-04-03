CXXFLAGS=-g -std=c++14
CC=$(CXX)
LINTFLAGS=--filter=-whitespace/braces,-build/namespaces,-runtime/references
INCS=$(shell ls *.h)
CPP_FILES=weather.cpp image.cpp date.cpp reading.cpp

weather_pre: weather.cpp
	clang --preprocess -std=c++14 weather.cpp

weather_comp: weather.cpp
	clang --compile -std=c++14 weather.cpp

test_date: date.cpp test_date.cpp

test_image: image.cpp test_image.cpp

weather: $(CPP_FILES)

weather_leaks: weather_leaks.cpp

tests: test_date test_image
	./test_date
	./test_image

lint:
	cpplint $(LINTFLAGS) $(CPP_FILES)

prod: tests
	-git commit -a 
	git push origin master

nocrud:
	-rm *~
	-rm .*swp
