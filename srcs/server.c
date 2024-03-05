void	ft_ask_server_pid(void)
{
	ft_putstr_color(GREEN, "server pid: ", 1);
	ft_printf(GREEN"%d\n\n", getpid());
}

void    ft_handle_signal(int signal)
{
	static int	bit;
	static char	c;

	bit = 0;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit += 1;
	if (bit == 8)
	{
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
	(void)argv;
	if (argc != 1)
	{
		ft_print_error_msg();
		ft_print_server_error_msg();
	}
	ft_ask_server_pid();
	while (1)
	{
		signal(SIGUSR1, ft_handle_signal);
		signal(SIGUSR2, ft_handle_signal);
	}
	return (EXIT_FAILURE);
}
