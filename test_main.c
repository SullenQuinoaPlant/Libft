/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:43:54 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 09:46:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "h.h"


int		main(int ac, char **av)
{
	(void) ac;
	(void) av;

#ifndef TF
	printf("no function selection was made");
#elif TF == ATOI
	if (ac == 2)
	{
		if (atoi(av[1]) != ft_atoi(av[1]))
		{
			printf("atoi is : %d\n", atoi(av[1]));
			printf("\nft_atoi is :%d", ft_atoi(av[1]));
		}
	}
	else
		printf("ft_atoi requires exactly one string as argument");
#elif TF == ITOA
	if (ac == 2)
	{
		int	i;
		char	*a;

		i = atoi(av[1]);
		a = ft_itoa(i);
		printf("\nprintf gives: %d, ft_itoa gives: %s", i, a);
		free(a);
	}
	else
		printf("test of ft_itoa requires exactly one arument");
#elif TF == MEMCCPY
	if (ac == 2)
	{
		size_t	l;
		char	*buff;

		l = strlen(av[1]);
		if ((buff = malloc(l + 1))
			buff[l] = '\0';
		free(buff);
	}
#elif TF == MEMCPY
	if (ac == 2)
	{
		char    *dest;
        size_t  length;

        length = strlen(av[1]);
        if (!(dest = malloc(length + 1)))
		{
			printf("malloc call failed, in MEMCPY test\n");
			return (0);
		}
		if ((length = strcmp(ft_memcpy(dest, av[1], length), av[1])))
		{
			printf("ft_memcpy failed. return val of strcmp is: %d", length);
		}
		free(dest);
	}
	else
		printf("ft_memcpy test requires exactly one argument");
#elif TF == PUTNBR
	if (ac == 2)
	{
		int	t;

		t = atoi(av[1]);
		printf("printf gives : %d\t and putnbr gives: ", t);
		ft_putnbr(t);
	}
#elif TF == STRNEQU
	if (ac == 4)
	{
		printf("\nreturn value of ft_strnequ(a1, a2) is : %d",\
			ft_strnequ(av[1], av[2], atoi(av[3])));
	}
	else
		printf("ft_strnequ test requires exactly three arguments:\
			string1, string2 and number of bytes to compare");
#elif TF == STREQU
	if (ac == 3)
	{
		printf("\nreturn value of ft_strequ(a1, a2) is : %d",\
			ft_strequ(av[1], av[2]));
	}
	else
		printf("ft_strequ test requires exactly two strings as arguments");
#elif TF == STRITER
	if (ac == 2)
	{
		void	here_f(char *c)
		{
			*c = 'h';
		}
		ft_striter(av[1], here_f);
		printf("\nresult of ft_striter is :\n%s", av[1]);
	}
	else
		printf("test of ft_striter requires exactly one argument");
#elif TF == STRITERI
	if (ac == 2)
	{
		void	here_f(unsigned int i, char *c)
		{
			i % 2 ? *c = 'h' : (1);
		}
		ft_striteri(av[1], here_f);
		printf("\nresult of ft_striter is :\n%s", av[1]);
	}
	else
		printf("test of ft_striteri requires exactly one argument");
#elif TF == STRJOIN
	if(ac == 3)
	{
		char	*s;

		s = ft_strjoin(av[1], av[2]);
		printf("\nresult of ft_strjoin(av[1], av[2]) is : %s", s);
	}
#elif TF == STRMAP
	if (ac == 2)
	{
		char	*s;
		char	here_f(char c)
		{
			return (c + 1);
		}

		s = ft_strmap(av[1], here_f);
		printf("\nresult of ft_strmap is :\n%s", s);
	}
	else
		printf("test of ft_strmap requires exactly one argument");
#elif TF == STRSUB
	if (ac == 4)
	{
		char	*s;

		s = ft_strsub(av[1], atoi(av[2]), atoi(av[3]));
		printf("\nreturned string is: %s", s);
	}
#elif TF == MEMALLOC
	if (ac == 2)
	{
		void	*new_buff;
		int		size;

		size = atoi(av[1]);
		new_buff = ft_memalloc(size);
		if (!new_buff)
			return (1);
		while (size--)
			if (((char*)new_buff)[size])
				printf("\nmemalloc failed, found a byte at : %c",\
					 ((char*)new_buff)[size]);
		free(new_buff);
	}
	else
		printf("memalloc test requires one numeric argument");
#elif TF == STRRCHR
	if (ac == 3)
	{
		printf("\nargument 1 is: %s\nargument 2 is: %c", av[1], av[2][0]);
		if (ft_strrchr(av[1], (int)av[2][0]) == strrchr(av[1], (int)av[2][0]))
			printf("\nft_strrchr and strrchr returned same value");
	}
	else
		printf("ft_strrchr test requires exactly 2 arguments");
	return (0);
#elif TF == STRSPLIT
	if (ac == 3)
	{
		char	**splits;

		splits = ft_strsplit(av[1], av[2][0]);
		while (*splits)
		{
			printf("\n%s",*splits++);
		}
	}
	else
		printf("\nft_strsplit test requires exactly two arguments.");
#else
	printf("no function selection was made");
#endif
	return (0);
}
