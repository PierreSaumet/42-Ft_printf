/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbersxthree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:02:34 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:02:36 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_nownosignprec(t_data data, t_tmp tmp)
{
	while (*data.pt_prec > tmp.i)
	{
		ft_putchar('0', data);
		*data.pt_prec -= 1;
	}
	ft_display(data, tmp);
}

void					ft_nowidth(t_data data, t_tmp tmp)
{
	if (*tmp.pt_sign)
	{
		if (*data.pt_prec > tmp.i)
			ft_nowsignprec(data, tmp);
		else
			ft_nowsign(data, tmp);
	}
	else
	{
		if (*data.pt_prec > 0)
			ft_nownosignprec(data, tmp);
		else
		{
			if ((!(tmp.i == 1 && tmp.tmp[0] == '0')) || *data.pt_prec2 != -1)
				ft_display(data, tmp);
		}
	}
}

void					ft_elseflagsleft(t_data data, t_tmp tmp, int i, char c)
{
	if (tmp.i == 1 && tmp.tmp[0] == '0')
	{
		while (i < *data.pt_width)
		{
			ft_putchar(' ', data);
			i++;
		}
	}
	else
	{
		i = tmp.i;
		ft_display(data, tmp);
		while (i < *data.pt_width)
		{
			ft_putchar(c, data);
			i++;
		}
	}
}

void					ft_elseflagsnoleft(t_data data, t_tmp tmp, int i)
{
	if (tmp.i == 1 && tmp.tmp[0] == '0')
	{
		while (i < *data.pt_width)
		{
			ft_putchar(' ', data);
			i++;
		}
	}
	else
	{
		while (i < (*data.pt_width - tmp.i))
		{
			ft_putchar(' ', data);
			i++;
		}
		ft_display(data, tmp);
	}
}

void					ft_elsenoprec(t_data data, t_tmp tmp, int i, char c)
{
	if (tmp.i > *data.pt_width)
		ft_display(data, tmp);
	else if (tmp.i < *data.pt_width)
	{
		if (*data.pt_flags & LEFT)
			ft_elseflagsleft(data, tmp, i, c);
		else
			ft_elseflagsnoleft(data, tmp, i);
	}
	else
	{
		if (tmp.i == 1 && tmp.tmp[0] == '0')
		{
			while (i < *data.pt_width)
			{
				ft_putchar(' ', data);
				i++;
			}
		}
		else
			ft_display(data, tmp);
	}
}
