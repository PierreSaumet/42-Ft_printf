/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberxfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:25:50 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:25:52 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_elseelse(t_data data, t_tmp tmp, int i)
{
	if (*data.pt_prec > tmp.i)
	{
		while (i < (*data.pt_prec - tmp.i))
		{
			ft_putchar('0', data);
			i++;
		}
	}
	ft_display(data, tmp);
}

void					ft_elsesignelseelse(t_data data, t_tmp tmp, int i)
{
	ft_putchar(*tmp.pt_sign, data);
	if (*data.pt_prec > tmp.i)
	{
		while (i < (*data.pt_prec - tmp.i))
		{
			ft_putchar('0', data);
			i++;
		}
	}
	ft_display(data, tmp);
}

void					ft_elsesignleftelse(t_data data, t_tmp tmp, int i)
{
	if (*data.pt_prec == tmp.i)
	{
		ft_putchar(*tmp.pt_sign, data);
		ft_display(data, tmp);
	}
	else if (*data.pt_prec > tmp.i)
	{
		ft_putchar(*tmp.pt_sign, data);
		i = tmp.i;
		while (i < *data.pt_prec)
		{
			ft_putchar('0', data);
			i++;
		}
		ft_display(data, tmp);
	}
	else
	{
		ft_putchar(*tmp.pt_sign, data);
		ft_display(data, tmp);
	}
}

void					ft_elsesignelseleftprec(t_data data, t_tmp tmp)
{
	if (tmp.i == 1)
	{
		ft_putchar(*tmp.pt_sign, data);
		ft_display(data, tmp);
	}
}

void					ft_elsesignelse(t_data data, t_tmp tmp, int i)
{
	if (*data.pt_flags & LEFT)
	{
		if (*data.pt_prec == 0)
			ft_elsesignelseleftprec(data, tmp);
		else
			ft_elsesignleftelse(data, tmp, i);
	}
	else
		ft_elsesignelseelse(data, tmp, i);
}
