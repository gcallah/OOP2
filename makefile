# A template makefile that works for static websites.
# Need to export as ENV var
export TEMPLATE_DIR = templates
PTML_DIR = html_src
UTILS_DIR = utils
CPP2HTML = python3 $(UTILS_DIR)/cpp2html.py
CODE_DIR = code
MISC_DIR = $(CODE_DIR)/misc

INCS = $(TEMPLATE_DIR)/head.txt $(TEMPLATE_DIR)/logo.txt $(TEMPLATE_DIR)/menu.txt

HTMLFILES = $(shell ls $(PTML_DIR)/*.ptml | sed -e 's/.ptml/.html/' | sed -e 's/html_src\///')

FORCE:

%.html: $(PTML_DIR)/%.ptml $(INCS)
	python3 $(UTILS_DIR)/html_checker.py $< 
	$(UTILS_DIR)/html_include.awk <$< >$@
	git add $@

code_pages: base_conv complex recursion stl

base_conv: $(PTML_DIR)/base_conv.ptml
complex: $(PTML_DIR)/complex.ptml
recursion: $(PTML_DIR)/recursion.ptml
stl: $(PTML_DIR)/stl.ptml

$(PTML_DIR)/base_conv.ptml: $(MISC_DIR)/base_conv.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/complex.ptml: $(MISC_DIR)/complex.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/recursion.ptml: $(MISC_DIR)/recursion.cpp
	$(CPP2HTML) $< > $@

$(PTML_DIR)/stl.ptml: $(MISC_DIR)/stl.cpp
	$(CPP2HTML) $< > $@

recursion: FORCE
	python3 $(UTILS_DIR)/cpp2html.py $(MISC_DIR)/recursion.cpp > $(PTML_DIR)/recursion.ptml

complex: FORCE
	python3 $(UTILS_DIR)/cpp2html.py $(MISC_DIR)/complex.cpp > $(PTML_DIR)/complex.ptml

local: $(HTMLFILES)

tests: FORCE
	cd code/misc; make tests
	cd code/weather; make tests
	cd code/vector; make tests
	cd code/linked; make tests

prod: $(INCS) $(HTMLFILES) tests
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
