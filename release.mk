NAME = libft
OBJ_DIR = ./sources
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CFLAGS := -Wall -Wextra -Werror -I ./includes

.PHONY : all
all: $(NAME).a

.PHONY : $(NAME)
$(NAME) : $(NAME).a

$(NAME).a: $(OBJS)
	ar rcs $@ $^

%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

.PHONY : clean
clean:
	-rm $(OBJS)

.PHONY : fclean
fclean: clean
	-rm $(NAME).a

.PHONY : re
re: fclean all
