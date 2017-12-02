#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return;
	while (n--)
		s[n] = '\0';
}
