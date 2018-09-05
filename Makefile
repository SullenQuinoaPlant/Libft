TARGETS :=\
tft_atoi \
tft_atoierr \
tft_bzero \
tft_cleanfree \
tft_isalnum \
tft_isalpha \
tft_isascii \
tft_isdigit \
tft_isprint \
tft_itoa \
tft_lstadd \
tft_lstdel \
tft_lstdelone \
tft_lstiter \
tft_lstmap \
tft_lstnew \
tft_memalloc \
tft_memccpy \
tft_memchr \
tft_memcmp \
tft_memcpy \
tft_memdel \
tft_memmove \
tft_memset \
tft_putchar \
tft_putchar_fd \
tft_putendl \
tft_putendl_fd \
tft_putnbr \
tft_putnbr_fd \
tft_putstr \
tft_putstr_fd \
tft_strcat \
tft_strchr \
tft_strclr \
tft_strcmp \
tft_strcpy \
tft_strdel \
tft_strdup \
tft_strequ \
tft_striter \
tft_striteri \
tft_strjoin \
tft_strlcat \
tft_strlen \
tft_strmap \
tft_strmapi \
tft_strncat \
tft_strncmp \
tft_strncpy \
tft_strnequ \
tft_strnew \
tft_strnstr \
tft_strrchr \
tft_strsplit \
tft_strstr \
tft_strsub \
tft_strtrim \
tft_tolower \
tft_toupper
NAME = libft
OBJ_DIR = ./sources
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

GCCFLAGS := -Wall -Wextra -Werror -I ./includes

.PHONY : all
all: $(NAME)

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
