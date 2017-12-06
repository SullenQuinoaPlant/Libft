int		ft_toupper(int c)
{
	return ((c >= 0141 && c <= 0172) ? ('A' + c - 'a') : c);
}
