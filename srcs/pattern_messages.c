/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:57:24 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 14:49:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_header(void)
{
	ft_printf(2, "\n\e[2m ####################################\e[0m");
	ft_printf(2, "\e[2m####################################\n\n\e[0m");
}

void	ft_print_footer(void)
{
	ft_print_header();
	exit(EXIT_FAILURE);
}
