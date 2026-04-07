
char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
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
