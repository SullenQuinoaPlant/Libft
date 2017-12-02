#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    if (!(dest && src))
        return (dest);
    while (n--)
        dest[n] = src[n];
    return (dest);
}
