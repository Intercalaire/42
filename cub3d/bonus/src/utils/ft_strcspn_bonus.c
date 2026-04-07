
int	ft_strcspn(const char *s, char *reject)
{
	int	i;
	int	j;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
