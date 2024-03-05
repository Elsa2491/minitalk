void	ft_ask_server_pid(void)
{
	ft_putstr_color(GREEN, "server pid: ", 1);
	ft_printf(GREEN"%d\n\n", getpid());
}

void    ft_handle_signal(int signal, siginfo_t *info, void *s)
{
	(void)s;
	static int	bit;
	static char	c;
	pid_t	pid;

	bit = 0;
	if (info->si_pid)
		pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		if (c == '\0')
			kill(pid, SIGUSR1);
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	ft_print_server_error_msg(void)
{
	// Add error msg cf: fractol
	return (EXIT_FAILURE);
}

void	ft_print_error_msg(void)
{
	ft_putstr_color(RED, "Warning: ", 1);
	ft_putstr_color(RESET, "invalid argument\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;

	(void)argv;
	if (argc != 1)
	{
		ft_print_error_msg();
		ft_print_server_error_msg();
	}
	ft_ask_server_pid();
	sig_action.sa_sigaction = ft_handle_signal;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &ft_handle_signal, NULL);
		sigaction(SIGUSR2, &ft_handle_signal, NULL);
	}
	return (EXIT_FAILURE);
}
