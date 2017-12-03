#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	if (!(dest && src))
		return (0);
	while (n--)
	{
		*(dest++) = *(src);
		if (!(*src++))
			break;
	}
	while (n--)
		*(dest++) = '\0';
	return (dest - n);
}
