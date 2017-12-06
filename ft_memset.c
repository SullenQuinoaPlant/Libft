#include <string.h>

void    *ft_memset(void *s, int c, size_t n)
{
    if (!s)
        return (s);
    while (n--)
        ((char*)s)[n] = (char)c;
    return (s);
}
