int	search_env(t_data *data, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (data->env[i])
	{
		if (ft_strncmp(str, data->env[i], len) == 0 && (data->env[i][len] == '='
			|| data->env[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}
