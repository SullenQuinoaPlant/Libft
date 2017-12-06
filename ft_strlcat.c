#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i == size &&  dst[i])
		return (size);
	size -= i + 1;
	while (size-- && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	while (*src++)
		i++;
	return (i);
}
