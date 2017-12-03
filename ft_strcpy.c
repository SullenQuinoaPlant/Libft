#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (!(dest && src))
		return (0);
	i = 0;
	while ((dest[i] = src[i]))
		i++;
	return (dest);
}
