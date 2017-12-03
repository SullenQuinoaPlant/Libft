#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle size)
{
	size_t	i;

	if (!*needle)
		return (haystack);
	while (size && *haystack)
	{
		i = 0;
		while (size - i && haystack[i] == needle[i] && haystack[i])
			i++;
		if (needle[i] == '\0')
			return (haystack);
		size--;
		haystack++;
	}
	return (0);
}
