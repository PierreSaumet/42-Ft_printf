/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:46:44 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:52:49 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file contains functions used to display characters or string
**	check if the integer, is a digit and
**	t_turbo_atoi is a different atoi, lighter.
**	'ft_putchar' display a character and used data to increase the counter.
**	'ft_putstr' uses ft_putchar.
**	'ft_isdigit' checks if it is an integer or not.
**	'ft_turbo_atoi' another version of atoi.
*/

void	ft_putchar(char c, t_data data)
{
	write(1, &c, 1);
	*data.pt_count += 1;
	return ;
}

void	ft_putstr(char *str, t_data data)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], data);
		i++;
	}
	return ;
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_turbo_atoi(const char **str)
{
	int		i;

	i = 0;
	while (ft_isdigit(**str))
	{
		i = i * 10 + *((*str)++) - '0';
	}
	return (i);
}
