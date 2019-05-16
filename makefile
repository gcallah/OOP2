# A template makefile that works for static websites.
# Need to export as ENV var
export TEMPLATE_DIR = templates
PTML_DIR = html_src
UTILS_DIR = utils
CPP2HTML = python3 $(UTILS_DIR)/cpp2html.py
CODE_DIR = code
MISC_DIR = $(CODE_DIR)/misc
WTHR_DIR = $(CODE_DIR)/weather
LINK_DIR = $(CODE_DIR)/linked
VECT_DIR = $(CODE_DIR)/vector

INCS = $(TEMPLATE_DIR)/head.txt $(TEMPLATE_DIR)/logo.txt $(TEMPLATE_DIR)/menu.txt

HTMLFILES = $(shell ls $(PTML_DIR)/*.ptml | sed -e 's/.ptml/.html/' | sed -e 's/html_src\///')

FORCE:

touch_cpp: FORCE
	cd $(LINK_DIR); touch *.cpp
	cd $(MISC_DIR); touch *.cpp
	cd $(VECT_DIR); touch *.cpp
	cd $(WTHR_DIR); touch *.cpp

code_pages: base_conv complex hello image recursion stl

base_conv: $(PTML_DIR)/base_conv.ptml
complex: $(PTML_DIR)/complex.ptml
hello: $(PTML_DIR)/hello.ptml
image: $(PTML_DIR)/image.ptml
recursion: $(PTML_DIR)/recursion.ptml
stl: $(PTML_DIR)/stl.ptml

$(PTML_DIR)/base_conv.ptml: $(MISC_DIR)/base_conv.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/complex.ptml: $(MISC_DIR)/complex.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/hello.ptml: $(MISC_DIR)/hello.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/image.ptml: $(WTHR_DIR)/image.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/recursion.ptml: $(MISC_DIR)/recursion.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/stl.ptml: $(MISC_DIR)/stl.cpp
	$(CPP2HTML) $< > $@

local: $(HTMLFILES) $(INCS)

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
