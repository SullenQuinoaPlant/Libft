/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:43:54 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/04 08:21:44 by nmauvari         ###   ########.fr       */
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
	return (0);
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
	return (0);
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
	return (0);
#elif TF == STRSPLIT
	if (ac == 3)
	{
		char	**splits;

		splits = ft_strsplit(av[1], av[2][0]);
		while (splits)
		{
			printf("\n%s",*splits++);
		}
	}
#else
	printf("no function selection was made");
	return (0);
#endif
}
