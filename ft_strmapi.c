#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	if ((ss = malloc(l + 1)))
		while (l--)
			ss[l] = f((unsigned int)l, s[l]);
	return (ss);
}
