/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:35:09 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 05:40:42 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include "../printf/srcs/ft_printf.h"

# define WARNING      " → Warning\n"
# define ARROW  "\t→ "

void	ft_print_header(void);
void	ft_print_footer(void);
#endif
