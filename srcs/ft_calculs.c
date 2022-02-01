/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:39:24 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:50:50 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file contains 2 functions to calculate the len of a string
**	ft_strlen and ft_strnlen (more informations, go see the man).
**	And 2 other functions one making a division and the second the
**	modulo. They are used to get a string from va_arg.
**	- 'ft_strlen' return the lengh of a string.
**	- 'ft_strnlen' return the lengh of a string with a lenmax.
**	- 'ft_do_div' return the division of two variables.
**	- 'ft_do_mod' return the modulo of two variables.
*/

int					ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int					ft_strnlen(const char *s, int lenmax)
{
	int len;

	len = 0;
	if (lenmax < 0)
	{
		len = ft_strlen(s);
		return (len);
	}
	else
	{
		while (s[len] && len < lenmax)
		{
			len++;
		}
	}
	return (len);
}

long int			ft_do_div(unsigned long n, unsigned base)
{
	n = n / base;
	return (n);
}

long int			ft_do_mod(unsigned long n, unsigned base)
{
	long int res;

	res = n % base;
	return (res);
}
