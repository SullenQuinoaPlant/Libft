static void	here_init(const char **nptr, unsigned long *ref,\
					unsigned long *res, int *fail)
{
	while (!((**nptr ^ ' ') && ((**nptr < '\t') || (**nptr > '\r'))))
		(*nptr)++;
	*ref = 0x1ul << (sizeof(unsigned long) * 8 - 1);
	*ref -= **nptr == '-' ? 0 : 1;
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
	fail = *comp > *ref ? 1 : fail;
	*res = *comp;
	*comp = *comp + (*(*nptr)++ - '0');
	fail = *comp > *ref ? 1 : fail;
	*res = *comp;
	return (fail);
}

int		ft_atoierr(const char *nptr,
			int *res, char **ret_p)
{
	unsigned long		res;
	unsigned long		ref;
	unsigned long		comp;
	int					fail;

	here_init(&nptr, &ref, &res, &fail);
	while (!fail && *nptr >= '0' && *nptr <= '9')
		fail = here_build_res(&comp, &res, &ref, &nptr);
	if (fail)
		*res = (int)ref;
	else
		*res = (int)(ref & 01 ? res : (~res) + 1);
	if (ret_p)
		*ret_p = nptr;
	return (fail);
}
