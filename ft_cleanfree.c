#include "libft.h"

void	ft_cleanfree(void *p, size_t sz)
{
	ft_bzero(p, sz);
	free(p);
}
