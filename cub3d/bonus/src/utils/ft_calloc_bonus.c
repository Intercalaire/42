
void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tab;
	size_t		i;
	long int	size_m;

	size_m = nmemb * size;
	if ((int)size_m < 0 || ((int)size < 0 && (int)nmemb < 0))
		return (NULL);
	i = 0;
	tab = malloc(size_m);
	if (tab == 0)
		return (0);
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
