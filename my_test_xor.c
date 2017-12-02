#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str = "aaaabc";

	while (!((*str ^ 'a') && (*str ^ 'b')))
		str++;
	printf("ptr to : %c", *str);
	return (0);
}
