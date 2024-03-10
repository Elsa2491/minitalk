/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 06:20:01 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/10 17:12:36 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_ask_server_pid(void)
{
	ft_printf(1, "Server PID\033[%dm %d\n\n\033[0m", 33, getpid());
}

void    ft_handle_signal(int signal, siginfo_t *info,  void __attribute__((unused))*s)
{
	static int	bit = 0;
	static char	c;
	pid_t	pid;

	if (info->si_pid)
		pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf(1, "\n");
			kill(pid, SIGUSR1);
		}
		ft_putchar_fd(1, c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;

	(void)argv;
	if (argc != 1)
		ft_print_server_error_msg();
	ft_ask_server_pid();
	sig_action.sa_sigaction = &ft_handle_signal;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sig_action, NULL);
		sigaction(SIGUSR2, &sig_action, NULL);
	}
	return (0);
}
