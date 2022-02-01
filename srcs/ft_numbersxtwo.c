/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbersxtwo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:02:44 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:02:48 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_noprecnosignleft(t_data data, t_tmp tmp)
{
	tmp.i--;
	while (tmp.i > -1)
	{
		ft_putchar((char)tmp.tmp[tmp.i], data);
		tmp.i--;
		*data.pt_width -= 1;
	}
	tmp.i = 1;
	while (*data.pt_width >= tmp.i)
	{
		ft_putchar(' ', data);
		tmp.i++;
	}
}

void					ft_noprecnosign(t_data data, t_tmp tmp, char c)
{
	while (*data.pt_width > tmp.i)
	{
		ft_putchar(c, data);
		*data.pt_width -= 1;
	}
	ft_display(data, tmp);
}

void					ft_noprec(t_data data, t_tmp tmp, int i, char c)
{
	if (*tmp.pt_sign)
	{
		if (*data.pt_flags & LEFT)
			ft_noprecsignflags(data, tmp, i);
		else
		{
			if (*data.pt_flags & ZERO)
				ft_noprecsignzero(data, tmp, c);
			else
				ft_noprecsign(data, tmp, c);
		}
	}
	else
	{
		if (*data.pt_flags & LEFT)
			ft_noprecnosignleft(data, tmp);
		else
			ft_noprecnosign(data, tmp, c);
	}
}

void					ft_nowsignprec(t_data data, t_tmp tmp)
{
	if ((*data.pt_flags & PLUS) && (!(*tmp.pt_sign)))
		ft_putchar('+', data);
	ft_putchar((char)*tmp.pt_sign, data);
	while (*data.pt_prec > tmp.i)
	{
		ft_putchar('0', data);
		*data.pt_prec -= 1;
	}
	ft_display(data, tmp);
}

void					ft_nowsign(t_data data, t_tmp tmp)
{
	if ((*data.pt_flags & PLUS) && (!(*tmp.pt_sign)))
		ft_putchar('+', data);
	ft_putchar((char)*tmp.pt_sign, data);
	if (!(tmp.i == 1 && tmp.tmp[0] == '0'))
		ft_display(data, tmp);
}
