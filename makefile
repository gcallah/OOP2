# A template makefile that works for static websites.
# Need to export as ENV var
export TEMPLATE_DIR = templates
PTML_DIR = html_src
UTILS_DIR = utils
CODE_DIR = code
MISC_DIR = $(CODE_DIR)/misc

INCS = $(TEMPLATE_DIR)/head.txt $(TEMPLATE_DIR)/logo.txt $(TEMPLATE_DIR)/menu.txt

HTMLFILES = $(shell ls $(PTML_DIR)/*.ptml | sed -e 's/.ptml/.html/' | sed -e 's/html_src\///')

FORCE:

%.html: $(PTML_DIR)/%.ptml $(INCS)
	python3 $(UTILS_DIR)/html_checker.py $< 
	$(UTILS_DIR)/html_include.awk <$< >$@
	git add $@

stl: FORCE
	python3 $(UTILS_DIR)/cpp2html.py $(MISC_DIR)/stl.cpp > $(PTML_DIR)/stl.ptml

recursion: FORCE
	python3 $(UTILS_DIR)/cpp2html.py $(MISC_DIR)/recursion.cpp > $(PTML_DIR)/recursion.ptml

local: $(HTMLFILES)

prod: $(INCS) $(HTMLFILES)
	cd code/misc; make tests
	cd code/weather; make tests
	cd code/vector; make tests
	cd code/linked; make tests
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
