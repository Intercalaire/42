
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*stock;

	i = 0;
	stock = (char *) s;
	while (i < n)
	{
		stock[i] = c;
		i++;
	}
	return (stock);
}
