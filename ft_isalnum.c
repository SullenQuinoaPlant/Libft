int		isalnum(int c)
{
	return ((c >= 060 && c <= 071) || (c >= 101 && c <= 172) ? c : 0);
}
