# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/28 06:51:47 by nmauvari          #+#    #+#              #
#    Updated: 2018/01/28 06:56:28 by nmauvari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.mk

TF = 

test: all
	gcc $(GCCFLAGS) -D "$(TF)=1" -o tf.exe test_main.c $(NAME)

libft:
	cp ft_*.c libft/
	cp auteur libft/
	cp Makefile.mk libft/Makefile
	cp libft.h libft/

unit_tests: libft
	make -C ./libft-unit-tests/

.PHONY: test
