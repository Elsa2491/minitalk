/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 05:46:03 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_ask_server_pid(void)
{
	ft_printf(1, "Server PID\033[%dm %d\n\n\033[0m", 33, getpid());
}

void	ft_handle_signal(int signal)
{
	static int	bit = 0;
	static char	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		ft_putchar_fd(1, c);
		bit = 0;
		c = 0;
	}
}

void	ft_print_server_error_msg(void)
{
	ft_print_header();
	ft_printf(2, "\033[%dm%s\e\033[0m", 31, WARNING);
	ft_printf(2, " It seems something went wrong.\n");
	ft_printf(2, " You must enter only 1 parameter. See the example below\n");
	ft_printf(2, "\033[%dm%s\e\033[0m./server\n", 32, ARROW);
	ft_print_footer();
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		ft_print_server_error_msg();
	ft_ask_server_pid();
	while (1)
	{
		signal(SIGUSR1, ft_handle_signal);
		signal(SIGUSR2, ft_handle_signal);
	}
	return (0);
}
