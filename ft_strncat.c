#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest[i])
		i++;
	while (n-- && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
