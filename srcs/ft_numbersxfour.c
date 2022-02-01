/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbersxfour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:09:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:09:27 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_elsenoprecend(t_data data, t_tmp tmp, int i)
{
	if (*data.pt_prec > tmp.i)
	{
		while (i < (*data.pt_width - *data.pt_prec))
		{
			ft_putchar(' ', data);
			i++;
		}
		i = 0;
		while (i < (*data.pt_prec - tmp.i))
		{
			ft_putchar('0', data);
			i++;
		}
		ft_display(data, tmp);
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

void					ft_elsenosignleft(t_data data, t_tmp tmp, int i)
{
	i = tmp.i;
	while (*data.pt_prec > i)
	{
		ft_putchar('0', data);
		i++;
	}
	ft_display(data, tmp);
	while (*data.pt_width > *data.pt_prec)
	{
		ft_putchar(' ', data);
		*data.pt_prec += 1;
	}
}

void					ft_elsenosignleftno(t_data data, t_tmp tmp, int i)
{
	i = tmp.i;
	tmp.i--;
	while (tmp.i > -1)
	{
		ft_putchar((char)tmp.tmp[tmp.i], data);
		tmp.i--;
	}
	while (i < (*data.pt_width - tmp.i - 1))
	{
		ft_putchar(' ', data);
		i++;
	}
}

void					ft_elsenosignwidthup(t_data data, t_tmp tmp, int i,
							char c)
{
	if (*data.pt_prec == 0)
		ft_elsenoprec(data, tmp, i, c);
	else
	{
		if (*data.pt_flags & LEFT)
		{
			if (tmp.i < *data.pt_prec)
				ft_elsenosignleft(data, tmp, i);
			else
				ft_elsenosignleftno(data, tmp, i);
		}
		else
			ft_elsenoprecend(data, tmp, i);
	}
}

void					ft_elsewidthprec(t_data data, t_tmp tmp, int i)
{
	if (*data.pt_prec == tmp.i)
		ft_display(data, tmp);
	else if (*data.pt_prec > tmp.i)
	{
		while (i < (*data.pt_prec - tmp.i))
		{
			ft_putchar('0', data);
			i++;
		}
		ft_display(data, tmp);
	}
	else
	{
		if ((!(tmp.i == 1 && tmp.tmp[0] == '0')))
			ft_display(data, tmp);
		else if (*data.pt_prec2 != -1)
			ft_display(data, tmp);
	}
}
