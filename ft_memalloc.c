#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if ((new = malloc(size)))
		ft_memset(new, 0x00, size);
	return (new);
}
