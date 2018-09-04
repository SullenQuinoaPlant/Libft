ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
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

.PHONY : test-libft
test-libft : $(TEST_DIR)/test-libft

$(TEST_DIR)/test-libft:
	mkdir $@/
	cp $(ROOT)/Makefile $@/
	cp $(ROOT)/make_vars.mk $@/Makefile
	cat $(ROOT)/core.mk >> $@/Makefile
	cp -r  $(SRC_DIR) $@/

.PHONY : unit_tests
unit_tests:
	make -C ./libft-unit-tests/ f
