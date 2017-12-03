#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		diff;

	index = 0;
	while (!(diff = s1[index] - s2[index]) && s1[index++] && n--)
		;
	return (diff);
}
