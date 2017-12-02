int		tolower(int c)
{
	return ((c >= 0101 && c <= 0132) ? (c - 'A' + 'a') : c);
}
