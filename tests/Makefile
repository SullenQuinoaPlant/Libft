ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

TF = NO_TEST
.PHONY: test
test: all
	gcc $(GCCFLAGS)\
		-I $(SRC_DIR)\
		-D "$(TF)=1"\
 		$(TEST_DIR)/test_main.c\
		$(A_NAME)\
		-o $(TEST_DIR)/tf.exe
	./$(TEST_DIR)/tf.exe

.PHONY : test_libft
test_libft : $(TEST_DIR)/test_libft

.PHONY : $(TEST_DIR)/test_libft
$(TEST_DIR)/test_libft:
	-rm -rf $@
	mkdir $@/
	cp $(ROOT)/auteur $@/
	cp $(ROOT)/Makefile $@/
	cp $(ROOT)/targets.mk $@/
	cp $(ROOT)/make_vars.mk $@/Makefile
	cat $(ROOT)/core.mk >> $@/Makefile
	cp -r $(SRC_DIR) $@/
	cp -r $(INC_DIR) $@/

.PHONY : unit_tests
unit_tests: test_libft
	make -C $(TEST_DIR)/libft-unit-tests/ f
