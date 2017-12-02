#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (!(dest && src))
		return (0);
	while (n-- && ((int)*src != c))
		(*(dest++)) = (*(src++));
	*dest = n < 0 ? 0 : c;
}
