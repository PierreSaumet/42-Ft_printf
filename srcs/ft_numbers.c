/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:47:02 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 15:55:39 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file contains 5 functions, three of them are used to check the
**	flags, ft_other is used for a specific case and ft_number is the
**	main function.
**	'ft_other' display the string.
**	'ft_number' , the main function in this file.
**	'ft_flags_sign' checks the flag sign, return fmt.
**	'ft_flags_signint' checks the flag sign, return args (- or not).
**	'ft_flags_special' checks if there is a special flag.
*/

unsigned long		ft_flags_sign(t_tmp tmp, t_data data, long args)
{
	if (*data.pt_flags & SIGN)
	{
		if (args < 0)
		{
			*tmp.pt_sign = '-';
			args = -args;
		}
		else if (*data.pt_flags & PLUS)
		{
			*tmp.pt_sign = '+';
		}
		else if (*data.pt_flags & SPACE)
		{
			*tmp.pt_sign = ' ';
		}
	}
	return (args);
}

void				ft_swif(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	while (i < (*data.pt_width - len))
	{
		ft_putchar(c, data);
		i++;
	}
	ft_putstr((char *)s, data);
}

void				ft_selss(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	(void)len;
	while (i < (*data.pt_width - *data.pt_prec))
	{
		ft_putchar(c, data);
		i++;
	}
	i = 0;
	while (i < *data.pt_prec)
	{
		ft_putchar(*(char *)s, data);
		i++;
		s++;
	}
}

void				ft_ssdisplay(t_data data, const char *s, int i)
{
	while (i < *data.pt_prec)
	{
		ft_putchar(*(char *)s, data);
		i++;
		s++;
	}
}
