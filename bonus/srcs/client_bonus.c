/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 06:22:29 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/10 16:22:11 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void    ft_send_bits(pid_t pid, char c)
{
	int	i;
	unsigned char	bits;

	i = 7;
	while (i >= 0)
	{
		bits = (bits >> i) & 1;
		if (c == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i -= 1;
	}
}

/*
void    ft_send_bits(pid_t pid, char c)
{
	int    bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit += 1;
	}
}
*/

void    ft_send_message(pid_t pid, char *msg)
{
	int    i;

	i = 0;
	while (msg[i])
	{
		ft_send_bits(pid, msg[i]);
		i++;
	}
	ft_send_bits(pid, ' ');
}

void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf(1, "Message reçu\n");
	exit (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	base;

	i = 0;
	base = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	if (str[i] == '+' || str[i] == '-')
	{
		ft_printf(2, "PID can't be negative.\n");
		exit (1);
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		base = base * 10 + str[i] - 48;
		i += 1;
	}
	return (base);
}

int    main(int argc, char **argv)
{
	pid_t    pid;
	int        i;
	
	i = 2;
	signal(SIGUSR1, ft_confirm);
	if (argc < 3)
		ft_print_client_error_msg();
	pid = ft_atoi(argv[1]);
	while (i < argc && argv[i][0] != '\0')
		ft_send_message(pid, argv[i++]);
	ft_send_bits(pid, '\0');
	return (0);
}
