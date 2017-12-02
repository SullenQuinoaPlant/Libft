int		isprint(int c)
{
	return ((c >= 040 && c <= 0176) ? c : 0);
}
