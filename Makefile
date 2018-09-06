ifndef ROOT
	ROOT = .
endif

include  $(ROOT)/make_vars.mk
include  $(ROOT)/core.mk
include  $(SRC_DIR)/Makefile
include  $(TEST_DIR)/Makefile


.PHONY : release
$(ROOT)/release :
	-rm -rf $@
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
	cp $(INC_DIR)/*.h $@/sources
	mkdir $@/includes
	mv $@/sources/$(NAME).h $@/includes
	cp -r $(INC_DIR)/ $@/
	cp $(ROOT)/auteur $@/
	cp $(ROOT)/targets.mk $@/Makefile
	cat $(ROOT)/project.mk >> $@/Makefile
endef


tests: libft
	make -C $(ROOT)/libft-unit-tests/ f

.PHONY : c
gc :
	git commit -a -m i
