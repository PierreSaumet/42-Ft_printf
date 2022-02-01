/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:24:27 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/05 11:24:29 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file is the first part of 'pointer' conversion.
**	- 'ft_p' only used for va_arg.
**	- 'ft_number_p', initialize the structure tmp, check args ( < 0 or > 0).
**	- 'ft_digits_p' do the conversion, display the result if there is
**	no width or precision. Else continue the conversion.
**	- 'ft_digits_p_next' continue the treatment, checks if there is Flag LEFT.
**	- 'ft_num_p_prec' display the string.
*/

void				ft_p(t_data data, va_list args)
{
	ft_number_p((unsigned long)va_arg(args, void *), 16, data);
}

void				ft_num_p_prec(t_data data, t_tmp tmp)
{
	int				i;

	i = 0;
	while (tmp.i < (*data.pt_width - 2))
	{
		ft_putchar(' ', data);
		tmp.i++;
	}
	ft_putstr("0x", data);
	if (*data.pt_prec > tmp.i)
	{
		while (i < (*data.pt_prec - tmp.i))
		{
			ft_putchar('0', data);
			i++;
		}
	}
}

void				ft_number_p(long args, int base, t_data data)
{
	t_tmp			tmp;

	ft_init_t_tmp(&tmp);
	if (args == 0)
	{
		if (*data.pt_width == -1 && *data.pt_prec == -1)
			ft_putstr("0x0", data);
		else if (*data.pt_prec > -1)
			ft_num_p_prec(data, tmp);
		else
		{
			while (tmp.i < (*data.pt_width - 3))
			{
				ft_putchar(' ', data);
				tmp.i++;
			}
			ft_putstr("0x0", data);
		}
	}
	else
		ft_digits_p(args, base, data, tmp);
}

void				ft_digits_p_next(t_data data, t_tmp tmp, char c, int i)
{
	if (*data.pt_flags & LEFT)
	{
		i = tmp.i + 2;
		tmp.i--;
		ft_putstr("0x", data);
		ft_digits_p_display(data, tmp);
		tmp.i = 0;
		while (tmp.i < (*data.pt_width - i))
		{
			ft_putchar(c, data);
			i++;
		}
	}
	else
		ft_digits_p_no_f(data, tmp, c, i);
}

void				ft_digits_p(long args, int base, t_data data, t_tmp tmp)
{
	char			*digits;
	int				i;
	char			c;

	c = ' ';
	if (*data.pt_flags & ZERO)
		c = '0';
	i = 0;
	digits = "0123456789ABCDEF";
	while (args != 0)
	{
		tmp.res = (digits[ft_do_mod(args, base)]);
		args = ft_do_div(args, base);
		tmp.tmp[tmp.i] = tmp.res;
		tmp.i++;
	}
	tmp.tmp[tmp.i] = '\0';
	if (*data.pt_width == -1 && *data.pt_prec == -1)
	{
		tmp.i--;
		ft_putstr("0x", data);
		ft_digits_p_display(data, tmp);
	}
	else
		ft_digits_p_next(data, tmp, c, i);
}
