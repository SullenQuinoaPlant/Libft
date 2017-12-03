#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] && haystack[i])
	{
		while (*haystack != *needle && *haystack)
			haystack++;
		i = 0;
		while(haystack[i] == needle[i] && haystack[i])
			i++;
	}
	return (!needle[i] ? (char*)haystack : 0);
}
