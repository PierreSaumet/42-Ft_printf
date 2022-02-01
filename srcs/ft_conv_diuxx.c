/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_diuxx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:36:43 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:51:16 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file is the first part of all the possible conversion.
**	You will find the conversion for 'd', 'i', 'u', 'xX' and 'o'.
**	- 'ft_check_qual' used for 'l' and 'h'.
**	- 'ft_dui' used for '%d/u/i' check the width, prec, etc.
**	- 'ft_xx' used for'%x/X' check the width, prec, etc.
**	- 'ft_f' used for '%f' check the qual, etc.
*/

unsigned long		ft_check_qual(t_data data, va_list args)
{
	unsigned long num;

	num = 0;
	if (data.qual == 'l')
		num = va_arg(args, unsigned long);
	else if (data.qual == 'h')
	{
		num = (unsigned short)va_arg(args, int);
		if (data.flags & SIGN)
			num = (short)num;
	}
	else if (*data.pt_flags & SIGN)
		num = va_arg(args, int);
	else
		num = va_arg(args, unsigned int);
	return (num);
}

void				ft_dui(const char *fmt, t_data data, va_list args)
{
	unsigned long num;

	num = 0;
	if (*fmt == 'd' || *fmt == 'i')
		*data.pt_flags |= SIGN;
	num = ft_check_qual(data, args);
	ft_numberx(num, 10, data);
}

void				ft_xx(const char *fmt, t_data data, va_list args)
{
	unsigned long num;

	num = 0;
	if (*fmt == 'x')
		*data.pt_flags |= SMALL;
	num = ft_check_qual(data, args);
	ft_numberxa(num, 16, data);
}

void				ft_f(t_data data, va_list args)
{
	(void)data;
	(void)args;
}
