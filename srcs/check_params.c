/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:38:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/06 14:38:27 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

int	ft_is_digit(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i += 1;
	}
	if (i != n)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	base;

	i = 0;
	base = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		base = base * 10 + (str[i] - 48);
		i += 1;
	}
	return (base);
}
