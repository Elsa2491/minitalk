/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:38:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 14:42:06 by eltouma          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 2;
	if (argc < 3)
		ft_print_client_error_msg();
	if (!ft_is_digit(argv[1], 6))
		ft_print_wrong_pid_msg();
	pid = ft_atoi(argv[1]);
	while (i < argc && argv[i][0] != '\0')
		ft_send_message(pid, argv[i++]);
	ft_send_bits(pid, '\n');
	return (0);
}
