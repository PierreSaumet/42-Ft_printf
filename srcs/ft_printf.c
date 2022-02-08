/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:46:55 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:53:45 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file will contains all the main functions for this exercice.
**	- 'ft_printf' initialize the va_args list and a structure.
**	- 'ft_lst_printf' will browse a string and display it until it find
**	a '%' then apply severals functions and return the printed characters.
**	- 'ft_preview' will check the flags, width, prec and qual.
**	- 'ft_conversion' find the symbol of conversion.
*/

static const char	*ft_preview(t_data data, const char *fmt, va_list args)
{
	fmt = ft_flags(fmt, data);
	fmt = ft_width(fmt, args, data);
	fmt = ft_prec(fmt, args, data);
	fmt = ft_qual(fmt, data.pt_qual);
	return (fmt);
}

static const char	*ft_conversion(const char *fmt, va_list args, t_data data)
{
	if (*fmt == 'c')
		ft_c(data, args);
	else if (*fmt == 's')
		ft_s(data, args);
	else if (*fmt == '%')
		ft_pourcentage(fmt, data);
	else if (*fmt == 'p')
		ft_p(data, args);
	else if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u')
		ft_dui(fmt, data, args);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_xx(fmt, data, args);
	else
	{
		if (*fmt)
			ft_putchar((char)*fmt++, data);
		else
			--fmt;
	}
	fmt++;
	return (fmt);
}

static int		ft_lst_printf(t_data data, const char *fmt, va_list args)
{
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_init_t(&data);
			ft_putchar((char)*fmt, data);
			fmt++;
			continue;
		}
		fmt++;
		fmt = ft_preview(data, fmt, args);
		fmt = ft_conversion(fmt, args, data);
	}
	return (*data.pt_count);
}

int				ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_data	data;

	ft_init_t_data(&data);
	va_start(args, fmt);
	*data.pt_count = ft_lst_printf(data, fmt, args);
printf("printf = %d\n", 	*data.pt_count);
	va_end(args);
	printf("fin de printf = %d\n", data.count);
	return (data.count);
}
