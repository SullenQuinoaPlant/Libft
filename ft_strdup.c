#include <unistd.h>

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	length;

	length = ft_strlen(s);
	if ((new_s = malloc(length + 1))
		while (length--)
			new_s[length] = s[length];
	return (new_s);
}
