
void	paint_on_screen(t_vars *vars)
{
	int	x;

	x = 0;
	mlx_delete_image(vars->window, vars->images->screen);
	vars->images->screen = mlx_new_image(vars->window, WIDTH, HEIGHT);
	while (x < WIDTH)
	{
		raycast(vars, x);
		x++;
	}
	mlx_image_to_window(vars->window, vars->images->screen, 0, 0);
	mlx_set_instance_depth(vars->images->screen->instances, (int32_t)1);
}
