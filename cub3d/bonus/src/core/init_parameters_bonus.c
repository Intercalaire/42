
void	get_parameters(t_vars *vars, char **file)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	while (file && file[i])
	{
		get_textures(file[i], vars);
		if (file[i][skip_space(file[i])] == 'C'
			|| file[i][skip_space(file[i])] == 'F')
		{
			get_colors(file[i], vars);
			color++;
		}
		i++;
	}
	if (!vars->north || !vars->south || !vars->east || !vars->west
		|| color != 2)
	{
		ft_putstr_fd("Error\nAn error occured while getting textures! ?\n", 2);
		ft_free_vars(vars);
	}
}

void	north_south_textures(char *str, t_vars *vars, char dir)
{
	int	i;

	i = skip_space(str);
	if (dir == 'N')
	{
		if (str[i] == 'N' && str[i + 1] == 'O'
			&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
		{
			i += skip_space(&str[i + 2]);
			i += 2;
			i += skip_space(&str[i]);
			vars->north = copy(&str[i + 2]);
		}
	}
	if (dir == 'S')
	{
		if (str[i] == 'S' && str[i + 1] == 'O'
			&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
		{
			i += skip_space(&str[i + 2]);
			i += 2;
			i += skip_space(&str[i]);
			vars->south = copy(&str[i]);
		}
	}
}

void	initialize_vars(t_vars **vars, char *file)
{
	*vars = ft_calloc(1, sizeof(t_vars));
	if (!*vars)
		error_malloc(-1, NULL);
	init(*vars, file);
	if (!*vars)
		exit(1);
}
