
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		i = n - 1;
		while (i >= 0)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
