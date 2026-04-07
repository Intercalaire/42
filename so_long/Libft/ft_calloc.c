
void	*ft_calloc( size_t nmemb, size_t size)
{
	void	*total;

	if (nmemb != 0 && size != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	total = malloc(nmemb * size);
	if (total == NULL)
		return (NULL);
	ft_bzero(total, nmemb * size);
	return (total);
}
