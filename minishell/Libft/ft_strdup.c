
char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	str = NULL;
	str = ft_calloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i != 0)
	{
		str[j] = s[j];
		i--;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strndup(const char *s, int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && i < n)
		i++;
	str = NULL;
	str = ft_calloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i != 0)
	{
		str[j] = s[j];
		i--;
		j++;
	}
	str[j] = '\0';
	return (str);
}
