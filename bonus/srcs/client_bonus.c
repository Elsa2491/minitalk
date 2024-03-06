/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 06:22:29 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 06:55:44 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	ft_send_bits(pid, '\0');
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
	while (str[i] == 32 || (str[i] >= 48 && str[i] <= 57))
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
	int        i = 2;

	if (argc <= 2)
	{
		ft_printf(2, "Error: invalid arguments.\n");
		ft_printf(2,
				"Try this instead: ./client <SERVER_PID> <MESSAGE>\n");
		return (1);
	}
	signal(SIGUSR1, ft_confirm);
	while (i < argc && argv[i][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		ft_send_message(pid, argv[i]);
		i += 1;
	}

	return (0);
}

/*

   if (argc !=)	1 - on stock le pid_server
   c'est un int -> convertir en char
   itoa(getpid());
   2 - quelque soit la valeur de argv[1], argv[1] = pid_server (converti en char)
   ici on fait un strcmp, si ça return 1
   ici on écrase argv[1], quelle que soit sa valeur
   sinon
   ici on écrase argv[1], quelle que soit sa valeur
   3 - reconverti pid_server_char -> en int
   atoi(argv[1]);

   }*/