#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if ((ss = malloc(len + 1)))
	{
		ss[len] = '\0';
		while (len--)
			ss[len] = s[(size_t)start + len];
	}
	return (ss);
}
