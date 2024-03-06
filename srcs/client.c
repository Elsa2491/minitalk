/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:38:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 05:56:59 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

void	ft_send_bits(pid_t pid, char c)
{
	int	bit;

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

void	ft_send_message(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		ft_send_bits(pid, msg[i++]);
	ft_send_bits(pid, ' ');
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
		ft_printf(2, "PID can't be negative\n");
		exit (1);
	}
	while (!(str[i] >= 48 && str[i] <= 57))
	{
		ft_printf(2, "Wrong PID\n");
		exit(1);
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		base = base * 10 + (str[i] - 48);
		i += 1;
	}
	return (base);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 2;
	if (argc <= 2)
	{
		ft_printf(2, "Error: invalid arguments.\n");
		ft_printf(2, "Try this instead: ./client <SERVER_PID> <MESSAGE>\n");
		return (1);
	}
	while (i < argc && argv[i][0] != '\0') // && ft_strisnum(argv[1]) && argv[i][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		ft_send_message(pid, argv[i]);
		i += 1;
	}
	ft_send_bits(pid, '\n');
	return (0);
}
