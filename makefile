# Top level makefile for OOP course.
export TEMPLATE_DIR = templates
PTML_DIR = html_src
UTILS_DIR = utils
CPP2HTML = python3 $(UTILS_DIR)/cpp2html.py
CODE_DIR = code
MISC_DIR = $(CODE_DIR)/misc
FMISC_DIR = $(CODE_DIR)/misc/finished_code
WTHR_DIR = $(CODE_DIR)/weather
LINK_DIR = $(CODE_DIR)/linked/finished_code
VECT_DIR = $(CODE_DIR)/vector
RECURS_DIR = $(CODE_DIR)/recursion/finished_code

INCS = $(TEMPLATE_DIR)/head.txt $(TEMPLATE_DIR)/logo.txt $(TEMPLATE_DIR)/menu.txt

HTMLFILES = $(shell ls $(PTML_DIR)/*.ptml | sed -e 's/.ptml/.html/' | sed -e 's/html_src\///')

FORCE:

touch_cpp: FORCE
	cd $(LINK_DIR); touch *.cpp
	cd $(MISC_DIR); touch *.cpp
	cd $(VECT_DIR); touch *.cpp
	cd $(WTHR_DIR); touch *.cpp
	cd $(RECURS_DIR); touch *.cpp

code_pages: baseX base_conv complex exceptions funcs functors hello image mean mem memleak my_vec point point_class recursion stl thing vector_experiments towers

baseX: $(PTML_DIR)/baseX.ptml
base_conv: $(PTML_DIR)/base_conv.ptml
complex: $(PTML_DIR)/complex.ptml
exceptions: $(PTML_DIR)/exceptions.ptml
funcs: $(PTML_DIR)/funcs.ptml
functors: $(PTML_DIR)/functors.ptml
hello: $(PTML_DIR)/hello.ptml
image: $(PTML_DIR)/image.ptml
mean: $(PTML_DIR)/mean.ptml
mem: $(PTML_DIR)/mem.ptml
memleak: $(PTML_DIR)/memleak.ptml
my_vec: $(PTML_DIR)/my_vec.ptml
point: $(PTML_DIR)/point.ptml
point_class: $(PTML_DIR)/point_class.ptml
recursion: $(PTML_DIR)/recursion.ptml
stl: $(PTML_DIR)/stl.ptml
thing: $(PTML_DIR)/thing.ptml
towers: $(PTML_DIR)/towers.ptml
vector_experiments: $(PTML_DIR)/vector_experiments.ptml

$(PTML_DIR)/base_conv.ptml: $(MISC_DIR)/base_conv.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/baseX.ptml: $(RECURS_DIR)/baseX.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/complex.ptml: $(MISC_DIR)/complex.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/exceptions.ptml: $(MISC_DIR)/exceptions.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/funcs.ptml: $(MISC_DIR)/funcs.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/functors.ptml: $(FMISC_DIR)/functors.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/hello.ptml: $(MISC_DIR)/hello.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/image.ptml: $(WTHR_DIR)/image.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/mean.ptml: $(FMISC_DIR)/mean.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/mem.ptml: $(FMISC_DIR)/mem.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/memleak.ptml: $(MISC_DIR)/memleak.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/my_vec.ptml: $(VECT_DIR)/my_vec.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/point.ptml: $(FMISC_DIR)/point.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/point_class.ptml: $(FMISC_DIR)/point_class.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/recursion.ptml: $(MISC_DIR)/recursion.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/stl.ptml: $(FMISC_DIR)/stl.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/thing.ptml: $(MISC_DIR)/thing.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/towers.ptml: $(RECURS_DIR)/towers.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/vector_experiments.ptml: $(VECT_DIR)/vector_experiments.cpp
	$(CPP2HTML) $< > $@

local: code_pages $(HTMLFILES) $(INCS)

%.html: $(PTML_DIR)/%.ptml $(INCS)
	python3 $(UTILS_DIR)/html_checker.py $< 
	$(UTILS_DIR)/html_include.awk <$< >$@
	git add $@

tests: FORCE
	cd $(LINK_DIR); make tests
	cd $(MISC_DIR); make tests
	cd $(VECT_DIR); make tests
	cd $(WTHR_DIR); make tests

prod: code_pages $(HTMLFILES) tests
	-git commit -a 
	git pull origin master
	git push origin master

submods:
	git submodule foreach 'git pull origin master'
	
nocrud:
	rm *~
	rm .*swp
	rm $(PTML_DIR)/*~
	rm $(PTML_DIR)/.*swp

clean:
	touch $(PTML_DIR)/*.ptml; make local
