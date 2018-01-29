# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 07:09:48 by nmauvari          #+#    #+#              #
#    Updated: 2018/01/28 07:36:19 by nmauvari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SO_NAME = libft.so

OBJS =  ft_atoi.o  ft_bzero.o  ft_isalnum.o  ft_isalpha.o  ft_isascii.o\
		ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o\
		ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o\
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o\
		ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o\
		ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o\
		ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o\
		ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o\
		ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o\
		ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o\
		ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o\
		ft_tolower.o ft_toupper.o

GCCFLAGS := -Wall -Wextra -Werror

A_STAMPS = was_liba is_liba
SO_STAMPS = was_libso is_libso

all: $(NAME)

is_liba: was_libso
	touch $(patsubst %.o, %.c, $(OBJS))

was_liba:
	touch was_liba

set_flags_a:
	$(eval GCCFLAGS := -Wall -Wextra -Werror)

$(NAME): is_liba set_flags_a $(OBJS)
	ar rcs $(NAME) $(OBJS)
	touch $(A_STAMPS)

is_libso: was_liba
	touch $(patsubst %.o, %.c, $(OBJS))

was_libso:
	touch was_libso

set_flags_so:
	$(eval GCCFLAGS += -fPIC -shared)

so: is_libso set_flags_so $(OBJS) 
#	ld -o libft.so $(OBJS) -lc
	gcc $(GCCFLAGS) -o $(SO_NAME) $(OBJS)
	touch $(SO_STAMPS)

%.o: %.c
	gcc -c $(GCCFLAGS) $<

clean:
	-rm *.o

fclean: clean
	-rm $(NAME)
	-rm $(SO_STAMPS) $(A_STAMPS)
	-rm $(SO_NAME)

re: fclean all

.PHONY: all clean fclean re
