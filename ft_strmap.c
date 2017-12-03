#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ss;
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	if ((ss = malloc(l + 1)))
		while (l--)
			ss[l] = f(s[l]);
	return (ss);
}
