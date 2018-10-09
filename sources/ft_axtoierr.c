/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axtoierr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 04:58:32 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/06 01:27:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void							here_init(
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

static int							here_build_res(
	unsigned long *p_res,
	unsigned long ref,
	unsigned long digit)
{
	unsigned long	res;
	unsigned long	comp;
	int				fail;
	int				i;

	res = *p_res;
	fail = 0;
	i = 4;
	while (i--)
		if ((comp = res << 1) > ref || comp < res)
		{
			fail = 1;
			break;
		}
		else
			res = comp;
	if (!fail)
		res |= digit;
	*p_res = res;
	return (fail);
}

static int							is_digit(
	char c,
	unsigned long *digit)
{
	if (c > '/' && c < ':')
		*digit = c - '0';
	else if (c > '@' && c < 'G')
		*digit = c - 'A' + 10;
	else if (c > '`' && c < 'g')
		*digit = c - 'a' + 10;
	else
		return (0);
	return (1);
}

int									ft_axtoierr(
	const char *nptr,
	int *ret_res,
	char **ret_p)
{
	unsigned long		res;
	unsigned long		ref;
	unsigned long		digit;
	int					fail;

	here_init(&nptr, &ref, &res, &fail);
	while (is_digit(*nptr, &digit) &&
		!(fail = here_build_res(&res, ref, digit)))
		nptr++;
	if (fail)
		*ret_res = (int)ref;
	else
		*ret_res = (int)(ref & 01 ? res : (~res) + 1);
	if (ret_p)
		*ret_p = (char*)nptr;
	return (fail);
}
