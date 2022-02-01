/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberssix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:40:03 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:40:04 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_elsesignleft(t_data data, t_tmp tmp, int i)
{
	ft_putchar(*tmp.pt_sign, data);
	while (i < *data.pt_prec)
	{
		ft_putchar('0', data);
		i++;
	}
	ft_display(data, tmp);
	i = 0;
	while (i < (*data.pt_width - *data.pt_prec - 1))
	{
		ft_putchar(' ', data);
		i++;
	}
}

void					ft_las(t_data data, t_tmp tmp, int i, char c)
{
	if (!(tmp.i == 1 && tmp.tmp[0] == '0'))
	{
		i = tmp.i;
		tmp.i--;
		while (tmp.i > -1)
		{
			ft_putchar((char)tmp.tmp[tmp.i], data);
			tmp.i--;
		}
		while ((i + 1) < *data.pt_width)
		{
			ft_putchar(c, data);
			i++;
		}
	}
	else
	{
		while (i < *data.pt_width)
		{
			ft_putchar(c, data);
			i++;
		}
	}
}

void					ft_elsesignleftelseif(t_data data, t_tmp tmp, int i,
							char c)
{
	ft_putchar(*tmp.pt_sign, data);
	if (*data.pt_prec == 0)
		ft_las(data, tmp, i, c);
	else
	{
		i = tmp.i;
		tmp.i--;
		while (tmp.i > -1)
		{
			ft_putchar((char)tmp.tmp[tmp.i], data);
			tmp.i--;
		}
		while (i < (*data.pt_width - 1))
		{
			ft_putchar(' ', data);
			i++;
		}
	}
}

void					ft_elsesignleftelses(t_data data, t_tmp tmp, int i,
							char c)
{
	ft_putchar(*tmp.pt_sign, data);
	if (!(tmp.i == 1 && tmp.tmp[0] == '0'))
	{
		i = tmp.i;
		tmp.i--;
		while (tmp.i > -1)
		{
			ft_putchar((char)tmp.tmp[tmp.i], data);
			tmp.i--;
		}
		while ((i + 1) < *data.pt_width)
		{
			ft_putchar(c, data);
			i++;
		}
	}
	while (i < (*data.pt_width - *data.pt_prec))
	{
		ft_putchar(' ', data);
		i++;
	}
}

void					ft_elsesignelses(t_data data, t_tmp tmp, int i)
{
	while (i < (*data.pt_width - *data.pt_prec - 1))
	{
		ft_putchar(' ', data);
		i++;
	}
	i = 0;
	ft_putchar(*tmp.pt_sign, data);
	while (i < (*data.pt_prec - tmp.i))
	{
		ft_putchar('0', data);
		i++;
	}
	ft_display(data, tmp);
}
