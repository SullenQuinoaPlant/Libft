#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*new;

	if ((new = malloc(size)))
		ft_memset(new, '\0', size);
	return ((char*)new);
}
