
int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	return (ft_strlen(s));
}
