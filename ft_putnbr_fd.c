#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		revn;
	int		high;
	char	d;

	revn = 0;
	high = 0;
	if (n < 0)
		write(fd, "-", 1);
	while (n / 10)
	{
		high++;
		revn = 10 * revn + n % 10;
		n /= 10;
	}
	d = '0' + (n > 0 ? n % 10 : -n % 10);
	write(fd, &d, 1);
	while (high--)
	{
		d = '0' + revn % 10 * (n > 0 ? 1 : -1);
		revn /= 10;
		write(fd, &d, 1);
	}
}
