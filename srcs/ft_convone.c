/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:59:38 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/08 17:59:41 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file is the first part of all the possible conversion.
**	You will find the conversion for 'c', 's', 'p' and '%'.
**	- 'ft_pourcentage' used for '%'.
**	- 'ft_c' used for '%c'.
**	- 'ft_end_c' used to printf the string from '%s'.
**	- 'ft_s' used for '%s'.
**	- 'ft_p' used for '%p' and used the functions with a p at the end.
*/

static void			ft_pourcentagewidth(t_data data, char c)
{
	if (*data.pt_flags & LEFT)
	{
		ft_putchar('%', data);
		while (*data.pt_width > 1)
		{
			ft_putchar(c, data);
			*data.pt_width -= 1;
		}
	}
	else
	{
		while (*data.pt_width > 1)
		{
			ft_putchar(c, data);
			*data.pt_width -= 1;
		}
		ft_putchar('%', data);
	}
	return ;
}

const char			*ft_pourcentage(const char *fmt, t_data data)
{
	char		c;

	c = ' ';
	if (*data.pt_flags & ZERO)
		c = '0';
	if (*data.pt_width > 1)
	{
		ft_pourcentagewidth(data, c);
	}
	else
		ft_putchar('%', data);
	fmt++;
	return (fmt);
}

static void			ft_displayc(t_data data)
{
	while (*data.pt_width > 1)
	{
		ft_putchar(' ', data);
		*data.pt_width -= 1;
	}
	return ;
}

void				ft_c(t_data data, va_list args)
{
	if (*data.pt_width > 0)
	{
		if (*data.pt_flags & LEFT)
		{
			ft_putchar((char)va_arg(args, int), data);
			ft_displayc(data);
		}
		else if (*data.pt_flags & ZERO)
		{
			while (*data.pt_width > 1)
			{
				ft_putchar('0', data);
				*data.pt_width -= 1;
			}
			ft_putchar((char)va_arg(args, int), data);
		}
		else
		{
			ft_displayc(data);
			ft_putchar((char)va_arg(args, int), data);
		}
	}
	else
		ft_putchar((char)va_arg(args, int), data);
	return ;
}

void				ft_sprec(t_data data, const char *s, int i, int len)
{
	if (*data.pt_prec == 0 && *data.pt_prec2 != -1)
		ft_putstr((char *)s, data);
	else
	{
		while (i < *data.pt_prec && i < len)
		{
			ft_putchar(*(char *)s, data);
			i++;
			s++;
		}
	}
	return ;
}
