TARGETS :=\
	ft_atoi \
	ft_atoierr \
	ft_bzero \
	ft_cleanfree \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_itoa \
	ft_lstadd \
	ft_lstdel \
	ft_lstdelone \
	ft_lstiter \
	ft_lstmap \
	ft_lstnew \
	ft_memalloc \
	ft_memccpy \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memdel \
	ft_memmove \
	ft_memset \
	ft_putchar \
	ft_putchar_fd \
	ft_putendl \
	ft_putendl_fd \
	ft_putnbr \
	ft_putnbr_fd \
	ft_putstr \
	ft_putstr_fd \
	ft_strcat \
	ft_strchr \
	ft_strclr \
	ft_strcmp \
	ft_strcpy \
	ft_strdel \
	ft_strdup \
	ft_strequ \
	ft_striter \
	ft_striteri \
	ft_strjoin \
	ft_strlcat \
	ft_strlen \
	ft_strmap \
	ft_strmapi \
	ft_strncat \
	ft_strncmp \
	ft_strncpy \
	ft_strnequ \
	ft_strnew \
	ft_strnstr \
	ft_strrchr \
	ft_strsplit \
	ft_strstr \
	ft_strsub \
	ft_strtrim \
	ft_supercleanfree \
	ft_tolower \
	ft_toupper
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
