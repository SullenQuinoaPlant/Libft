/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoierr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 04:58:32 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/06 01:27:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void						here_init(
	const char **nptr,
	unsigned long *ref,
	unsigned long *res,
	int *fail)
{
	while (!((**nptr ^ ' ') && ((**nptr < '\t') || (**nptr > '\r'))))
		(*nptr)++;
	*ref = 0x1ul << (sizeof(unsigned long) * 8 - 1);
	*ref -= **nptr == '-' ? 0 : 1;
	**nptr == '-' || **nptr == '+' ? (*nptr)++ : (*nptr);
	*res = 0;
	*fail = 0;
}

static int						here_build_res(
	unsigned long *p_res,
	unsigned long ref,
	const char c)
{
	unsigned long	res;
	unsigned long	comp;
	unsigned long	save;
	int				fail;

	res = *p_res;
	comp = res << 1;
	fail = comp > ref || comp < res ? 1 : 0;
	res = comp;
	save = res;
	comp = res << 1;
	fail = comp > ref || comp < res ? 1 : fail;
	res = comp;
	comp <<= 1;
	fail = comp > ref || comp < res ? 1 : fail;
	res = comp;
	comp += save;
	fail = comp > ref ? 1 : fail;
	res = comp;
	comp += c - '0';
	fail = comp > ref ? 1 : fail;
	*p_res = comp;
	return (fail);
}

int								ft_atoierr(
	const char *nptr,
	int *ret_res,
	char **ret_p)
{
	unsigned long		res;
	unsigned long		ref;
	char				c;
	int					fail;

	here_init(&nptr, &ref, &res, &fail);
	while (*nptr >= '0' && *nptr <= '9')
	{
		c = *nptr++;
		fail = here_build_res(&res, ref, c);
	}
	if (fail)
		*ret_res = (int)ref;
	else
		*ret_res = (int)(ref & 01 ? res : (~res) + 1);
	if (ret_p)
		*ret_p = (char*)nptr;
	return (fail);
}
