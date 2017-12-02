int		isalnum(int c)
{
	if ((c >= 060 && c <= 071) ||
	(c >= 0101 && c <= 0132) ||
	(c >= 0141 && c <= 0172))
		return (c);
	else
		return (0);
}
