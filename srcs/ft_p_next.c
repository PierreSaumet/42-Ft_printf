/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:14:16 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 12:14:17 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file is the second part of 'pointer' conversion.
**	- 'ft_digits_p_display' display the string.
**	- 'ft_digits_p_no_f', used if there is no flag.
*/

void				ft_digits_p_display(t_data data, t_tmp tmp)
{
	while (tmp.i > -1)
	{
		ft_putchar((char)tolower(tmp.tmp[tmp.i]), data);
		tmp.i--;
	}
}

void				ft_digits_p_no_f(t_data data, t_tmp tmp, char c, int i)
{
	while (i < (*data.pt_width - (tmp.i + 2)))
	{
		ft_putchar(c, data);
		i++;
	}
	ft_putstr("0x", data);
	if (*data.pt_prec > tmp.i)
	{
		i = 0;
		while (i < (*data.pt_prec - tmp.i))
		{
			ft_putchar('0', data);
			i++;
		}
	}
	tmp.i--;
	ft_digits_p_display(data, tmp);
}
