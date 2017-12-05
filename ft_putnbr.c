#include <unistd.h>
#include <stdlib.h>

static char	*here_recursion(int n, int rank, char **s)
{
	char	*w;

	if (n && (w = here_recursion(n / 10, rank + 1, s)))
	{
		if (n > 0)
			*w = '0' + n % 10;
		else
			*(w + 1) = '0' - n % 10;
		return (w + 1);
	}
	else if (rank)
	{
		if ((*s = malloc(rank + 1)))
			(*s)[rank] = '\0';
	}
	else if ((*s = malloc(2)))
	{
		(*s)[0] = '0';
		(*s)[1] = '\0';
	}
	return (*s);
}
	
static char	*here_itoa(int n)
{
	char		*s;
	int			sign;

	sign = n < 0 ? 1 : 0;
	here_recursion(n, sign, &s);
	if (sign && s)
		*s = '-';
	return (s);
}

void	ft_putnbr(int n)
{
	char	*s;

	s = here_itoa(n);
	if (s)
		while (*s)
			write(1, s++, 1);
}
