#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	i == size && dest[i] ? (return (size)) : (size -= i + 1);
	while (size-- && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	while (*src++)
		i++;
	return (i);
}
