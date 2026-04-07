
void	color_error(t_vars *vars)
{
	ft_putstr_fd("Error\nAn error occured while getting colors! ?\n", 2);
	ft_free_vars(vars);
	exit(1);
}

void	texture_error(t_vars *vars)
{
	ft_putstr_fd("Error\nAn error occurred while loading a texture!\n",
		2);
	ft_free_vars(vars);
	exit(1);
}

void	nb_arg_error(void)
{
	ft_putstr_fd("Error\nOnly one argument is required! ?\n", 2);
	exit(1);
}

void	empty_arg(void)
{
	ft_putstr_fd("Error\nEmpty argument! ?\n", 2);
	exit(1);
}

void	map_error(void)
{
	ft_putstr_fd("Error\nError occured on the map! ?\n", 2);
	exit(1);
}
