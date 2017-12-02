/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test_2cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 07:22:13 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/02 07:28:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(int ac, char **av)
{

	if (ac == 3)
	{
		unsigned char ua = *av[1];
		unsigned char ub = *av[2];
		printf("unsigned char subtraction: %u", ua - ub); 

		char a = *av[1];
		char b = *av[2];
		printf("\nsigned char subtraction: %d", (unsigned char)(a - b));
	}
	return (0);
}
