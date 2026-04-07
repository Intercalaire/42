
void	error_extention(void)
{
	ft_putstr_fd("Error\nNeed .cub extension! ?\n", 2);
	exit(1);
}

void	error_fd(void)
{
	ft_putstr_fd("Error\nFile descriptor error! ?\n", 2);
	exit(1);
}

void	error_read(int fd, char *buffer, char *getter)
{
	if (fd != -1)
		close(fd);
	if (buffer)
		free(buffer);
	if (getter)
	{
		free(getter);
		getter = NULL;
	}
	ft_putstr_fd("Error\nAn error occured while reading file! ?\n", 2);
	exit(1);
}

void	error_malloc(int fd, char **tab)
{
	if (fd != -1)
		close(fd);
	if (tab)
		ft_free(tab);
	ft_putstr_fd("Error\nMalloc error! ?\n", 2);
	exit(1);
}
