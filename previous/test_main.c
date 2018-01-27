/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:43:54 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/01 10:27:41 by nmauvari         ###   ########.fr       */
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
		printf("return of atoi is : %d\n", ft_atoi(av[1]));
	}
	return (0);
#else
	printf("no function selection was made");
	return (0);
#endif
}
