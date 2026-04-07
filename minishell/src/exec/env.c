
int	print_env(t_data *data, char **arg)
{
	int	i;

	i = 0;
	if (arg[0])
	{
		print_error("Minishell: env: ", arg[0], ": Too mush argument");
		return (1);
	}
	while (data->env[i])
	{
		if (ft_strchr(data->env[i], '='))
			printf("%s\n", data->env[i]);
		i++;
	}
	return (0);
}
