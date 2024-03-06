/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:38:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 14:51:14 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

void	ft_print_server_error_msg(void)
{
	ft_print_header();
	ft_printf(2, "\033[%dm%s\e\033[0m", 31, WARNING);
	ft_printf(2, " It seems something went wrong.\n");
	ft_printf(2, " You must enter only 1 parameter. See the example below\n");
	ft_printf(2, "\033[%dm%s\e\033[0m./server\n", 32, ARROW);
	ft_print_footer();
}

void	ft_print_client_error_msg(void)
{
	ft_print_header();
	ft_printf(2, "\033[%dm%s\e\033[0m", 31, WARNING);
	ft_printf(2, " It seems something went wrong.\n");
	ft_printf(2, " You must enter \e[1mat least\e[0m 3 parameters.");
	ft_printf(2, " See the example below\n");
	ft_printf(2, "\033[%dm%s\e\033[0m./client server_pid argv[2]\n", 32, ARROW);
	ft_print_footer();
}

void	ft_print_wrong_pid_msg(void)
{
	ft_printf(2, "\033[%dm%s\e\033[0m", 31, WARNING);
	ft_printf(2, " Wrong PID\n");
}
