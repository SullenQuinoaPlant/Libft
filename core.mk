.PHONY : all
all: $(NAME)

.PHONY : $(NAME)
$(NAME) : $(A_NAME)

$(ROOT)/$(A_NAME): is_liba $(OBJS)
	touch $(A_STAMPS)
	ar rcs $(A_NAME) $(OBJS)

was_libso:
	touch was_libso

is_liba: was_libso
	touch $(SRCS)
	$(eval GCCFLAGS := -Wall -Wextra -Werror)


.PHONY : so
so: $(ROOT)/$(SO_NAME)

$(ROOT)/$(SO_NAME) : is_libso $(OBJS)
	touch $(SO_STAMPS)
	gcc $(GCCFLAGS) -shared -o $(SO_NAME) $(OBJS)

was_liba:
	touch was_liba

is_libso: was_liba
	touch $(SRCS)
	$(eval GCCFLAGS += -fPIC)


%.o: %.c
	@gcc -c $(GCCFLAGS) $< -o $@


.PHONY : clean
clean:
	-rm $(OBJS)

.PHONY : fclean
fclean: clean
	-rm $(A_NAME) $(SO_NAME)
	-rm $(SO_STAMPS) $(A_STAMPS)

.PHONY : re
re: fclean all
