ifndef ROOT
 ROOT = ..
 include $(ROOT)/Makefile
endif

.PHONY : targets
targets : clean-targets $(ROOT)/targets.mk

.PHONY : clean-targets
clean-targets :
	rm $(ROOT)/targets.mk

.PHONY : $(ROOT)/targets.mk 
$(ROOT)/targets.mk :
	@echo "TARGETS :=\\" > $@
	@ls $(SRC_DIR)/*.c \
	|sed 's@.*/\([a-z0-9][a-z0-9_]*\)\.c@	\1 \\@' \
	|sed '$$s@\(.*\) \\@\1@' >> $@
