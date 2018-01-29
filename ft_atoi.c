/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:31:14 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/15 08:20:38 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	here_init(const char **nptr, unsigned long *ref,\
					unsigned long *res, int *fail)
{
	while (!((**nptr ^ ' ') && ((**nptr < '\t') || (**nptr > '\r'))))
		(*nptr)++;
	*ref = **nptr == '-' ? 0x8000000000000000 : 0x7fffffffffffffff;
	**nptr == '-' || **nptr == '+' ? (*nptr)++ : (*nptr);
	*res = 0;
	*fail = 0;
}

static int	here_build_res(unsigned long *comp, unsigned long *res,\
					unsigned long *ref, const char **nptr)
{
	unsigned long	save;
	int				fail;

	*comp = *res << 1;
	fail = *comp > *ref || *comp < *res ? 1 : 0;
	*res = *comp;
	save = *res;
	*comp = *res << 1;
	fail = *comp > *ref || *comp < *res ? 1 : fail;
	*res = *comp;
	*comp = *comp << 1;
	fail = *comp > *ref || *comp < *res ? 1 : fail;
	*res = *comp;
	*comp = *comp + save;
	fail = *comp > *ref || *comp < *res ? 1 : fail;
	*res = *comp;
	*comp = *comp + (*(*nptr)++ - '0');
	fail = *comp > *ref || *comp < *res ? 1 : fail;
	*res = *comp;
	return (fail);
}

int			ft_atoi(const char *nptr)
{
	unsigned long		res;
	unsigned long		ref;
	unsigned long		comp;
	int					fail;

	here_init(&nptr, &ref, &res, &fail);
	while (!fail && *nptr >= '0' && *nptr <= '9')
		fail = here_build_res(&comp, &res, &ref, &nptr);
	if (fail)
		return ((int)(ref));
	return ((int)(ref == 0x8000000000000000 ? (~res) + 1 : res));
}
