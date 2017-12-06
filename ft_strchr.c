char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s++)
		;
	return (*s == (char)c ? s : 0);
}
