
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*new_dest;
	unsigned char	*new_src;

	i = 0;
	new_dest = (unsigned char *) dest;
	new_src = (unsigned char *) src;
	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	while (i < n)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (new_dest);
}
