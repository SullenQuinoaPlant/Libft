char	*ft_strrchr(const char *s, int c)
{
	char	*prev;

	prev = 0;
	while (1)
	{
		prev = *s == (char)c ? (char*)s : prev;
		if (!*s++)
			break;
	}
	return (prev);
}
