# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 07:09:48 by nmauvari          #+#    #+#              #
#    Updated: 2018/09/01 05:22:05 by nmauvari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SO_NAME = libft.so

TARGETS :=\
		ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii\
		ft_isdigit ft_isprint ft_itoa ft_lstadd ft_lstdel\
		ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_memalloc\
		ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel\
		ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl\
		ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd\
		ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel\
		ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin\
		ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat\
		ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr\
		ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim\
		ft_tolower ft_toupper

TARGETS_EXTENSION :=\
	ft_atoierr ft_cleanfree

TARGETS += $(TARGETS_EXTENSION)

SRCS := $(patsubst %,%.c,$(TARGETS))
OBJS := $(patsubst %,%.o,$(TARGETS))

DEFFLAGS := -Wall -Wextra -Werror\
	-I includes/
SOFLAGS := -fPIC -shared
CFLAGS := $(DEFFLAGS)


A_STAMPS = was_liba is_liba
SO_STAMPS = was_libso is_libso


all: $(NAME)

was_libso:
	touch was_libso

is_liba: was_libso
	touch $(SRCS)
	$(eval CFLAGS := $(DEFFLAGS))

$(NAME): is_liba $(OBJS)
	touch $(A_STAMPS)
	ar rcs $(NAME) $(OBJS)

was_liba:
	touch was_liba

is_libso: was_liba
	touch $(SRCS)
	$(eval CFLAGS := $(DEFFLAGS) $(SOFLAGS)

so: is_libso $(OBJS)
	touch $(SO_STAMPS)
	gcc $(CFLAGS) -o $(SO_NAME) $(OBJS)

%.o: sources/%.c
	gcc -c $(CFLAGS) $<

clean:
	-rm *.o

fclean: clean
	-rm $(NAME) $(SO_NAME)
	-rm $(SO_STAMPS) $(A_STAMPS)

re: fclean all

.PHONY: all clean fclean re
