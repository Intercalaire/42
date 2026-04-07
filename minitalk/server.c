
void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	pid;

	(void)context;
	if (signum == SIGUSR1)
		c |= 1 << i;
	if (++i == 8)
	{
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	act.sa_sigaction = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
