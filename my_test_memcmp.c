/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 06:45:41 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/02 08:46:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_memcmp(const void *, const void *, size_t);

int		main(int ac, char **av)
{
	size_t	length;
	long	res;
	long	res2;

	if (ac == 3)
	{
		length = strlen(av[1]) + 1;
		length = (unsigned long) length > strlen(av[2]) + 1 ? strlen(av[2]) + 1 : length;
		printf("length is : %d", (int)length);
		res = memcmp(av[1], av[2], length);
		//res = memcmp(av[1], 0, length);
		printf("\nlength is : %d", (int)length);
		printf("\nres is : %d", (int)res);
		res2 = ft_memcmp(av[1], av[2], length);
		if (res == res2)
			printf("\nft_memcp and mem_cmp give the same result");
		printf("\nresult from ft_memcmp is: %ld", res2);
	}
	return (0);
}
