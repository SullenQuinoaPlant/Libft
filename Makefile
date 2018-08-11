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

TF = NO_TEST

test: all
	gcc $(GCCFLAGS) -D "$(TF)=1" -o tf.exe test_main.c $(NAME)
	./tf.exe

the_lib:
	-rm -rf $@/
	git clone\
		--single-branch --depth 1\
		-b the_lib\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$@/
	git rm $@/*
	cp ft_*.c $@/
	cp auteur $@/
	cp Makefile.mk $@/
	cp libft.h $@/
	cd $@ &&\
		git add * &&\
		git commit -a -m the_lib &&\
		git push

unit_tests: libft
	make -C ./libft-unit-tests/ f

.PHONY: test libft
