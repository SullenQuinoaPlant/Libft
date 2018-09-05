ifndef ROOT
	ROOT = .
endif

include  $(ROOT)/make_vars.mk
include  $(ROOT)/core.mk
include  $(SRC_DIR)/Makefile
include  $(TEST_DIR)/Makefile


.PHONY : release
release :
	-rm -rf $@/
	git clone\
		--single-branch --depth 1\
		-b release\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$@/
	rm -r $@/*
	$(RELEASE_FILES)
	cd $@ &&\
		git add * &&\
		git commit -a -m release &&\
		git push

define RELEASE_FILES
	mkdir $@/sources
	cp $(SRCS) $@/sources/
	mkdir $@/includes
	cp $(SRC_DIR)/*.h $@/includes/
	cp auteur $@/
	cp targets.mk $@/Makefile
	cat project.mk >> $@/Makefile
endef


tests: libft
	make -C ./libft-unit-tests/ f

.PHONY : c
gc :
	git commit -a -m i
