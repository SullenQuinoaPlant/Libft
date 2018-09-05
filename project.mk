NAME = libft
OBJ_DIR = ./sources
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

GCCFLAGS := -Wall -Wextra -Werror -I ./includes

.PHONY : all
all: $(NAME).a

$(NAME).a: $(OBJS)
	ar rcs $@ $^

%.o: %.c
	@gcc -c $(GCCFLAGS) $< -o $@

.PHONY : clean
clean:
	-rm $(OBJS)

.PHONY : fclean
fclean: clean
	-rm $(NAME).a

.PHONY : re
re: fclean all
