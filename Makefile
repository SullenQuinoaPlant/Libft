ifndef ROOT
	ROOT = .
endif

include  $(ROOT)/make_vars.mk
include  $(ROOT)/core.mk
include  $(SRC_DIR)/Makefile
include  $(TEST_DIR)/Makefile


define PROJECT_FILES
	mkdir $@/sources
	cp $(SRCS) $@/sources/
	mkdir $@/includes
	cp $(SRC_DIR)/*.h $@/includes/
	cp auteur $@/
	cp targets.mk $@/Makefile
	cat project.mk >> $@/Makefile
endef

.PHONY : project
project :
	-rm -rf $@/
	git clone\
		--single-branch --depth 1\
		-b project\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$@/
	rm -r $@/*
	$(PROJECT_FILES)
	cd $@ &&\
		git add * &&\
		git commit -a -m project &&\
		git push
