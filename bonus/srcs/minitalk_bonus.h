/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 06:17:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/10 16:39:36 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "../../printf/srcs/ft_printf.h"

# define WARNING      " → Warning\n"
# define ARROW  "\t→ "

void	ft_print_header(void);
void	ft_print_footer(void);
void	ft_print_server_error_msg(void);
void	ft_print_client_error_msg(void);
void	ft_print_wrong_pid_msg(void);
#endif
