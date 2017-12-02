int		isalpha(int c)
{
	if ((c >= 0101 && c <= 0132) ||
	(c >= 0141 && c <= 0172))
		return (c);
	else
		return (0);
}
