.PHONY : all
all: $(NAME)

.PHONY : $(NAME)
$(NAME) : $(ROOT)/$(A_NAME)

$(ROOT)/$(A_NAME): $(ROOT)/is_liba $(OBJS)
	touch $(A_STAMPS)
	ar rcs $@ $(OBJS)

$(ROOT)/was_libso:
	touch $@

$(ROOT)/is_liba: $(ROOT)/was_libso
	touch $(SRCS)
	$(eval SET_CFLAGS := $(CFLAGS)) 


.PHONY : so
so: $(ROOT)/$(SO_NAME)

$(ROOT)/$(SO_NAME) : $(ROOT)/is_libso $(OBJS)
	touch $(SO_STAMPS)
	gcc $(SET_CFLAGS) -shared -o $(SO_NAME) $(OBJS)

$(ROOT)/was_liba:
	touch $@

$(ROOT)/is_libso: $(ROOT)/was_liba
	touch $(SRCS)
	$(eval SET_CFLAGS += -fPIC)


%.o: %.c
	gcc -c $(SET_CFLAGS) $< -o $@


.PHONY : clean
clean:
	-rm $(OBJS)

.PHONY : fclean
fclean: clean
	-rm $(A_NAME) $(SO_NAME)
	-rm $(SO_STAMPS) $(A_STAMPS)

.PHONY : re
re: fclean all
