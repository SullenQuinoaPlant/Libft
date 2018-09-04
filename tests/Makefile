ifndef ROOT
	ROOT = ..
	include $(ROOT)\Makefile
endif

TF = NO_TEST
.PHONY: test
test: all
	gcc $(GCCFLAGS)\
		-D "$(TF)=1"\
 		$(TEST_DIR)/test_main.c\
		$(A_NAME)\
		-o $(TEST_DIR)/tf.exe
	./$(TEST_DIR)/tf.exe

$(TEST_DIR)/libft:
	mkdir $@/
	$(PROJECT_FILES)

.PHONY : unit_tests
unit_tests:
	make -C ./libft-unit-tests/ f
