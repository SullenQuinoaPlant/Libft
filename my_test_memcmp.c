/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 06:45:41 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/02 07:40:23 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_memcmp(const void *, const void *, size_t);

int		main(int ac, char **av)
{
	size_t	length;
	long	res;

	if (ac == 3)
	{
		length = strlen(av[1]) + 1;
		length = (unsigned long) length > strlen(av[2]) + 1 ? strlen(av[2]) + 1 : length;
		printf("length is : %d", (int)length);
		res = memcmp(av[1], av[2], length);
		//res = memcmp(av[1], 0, length);
		printf("res is : %d", (int)res);
		if (res == ft_memcmp(av[1], av[2], length))
			printf("\nft_memcp and mem_cmp give the same result");
	}
	return (0);
}
