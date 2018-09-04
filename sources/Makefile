ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

.PHONY : targets
targets : clean-targets $(ROOT)/targets.mk

.PHONY : clean-targets
	-rm $(ROOT)/targets.mk

$(ROOT)/targets.mk :
	echo "TARGETS :=\\" > $@
	@ls $(SRC_DIR)/*.c \
	|sed 's@.*/\([a-z0-9][a-z0-9_]*\)\.c@\t\1 \\@' \
	|sed '$$s@\(.*\) \\@\1@' >> $@
	$(eval include $(SRC_DIR)/targets.mk)
