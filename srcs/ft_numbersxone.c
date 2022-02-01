/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbersxone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:02:17 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:02:23 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_display(t_data data, t_tmp tmp)
{
	tmp.i--;
	while (tmp.i > -1)
	{
		ft_putchar((char)tmp.tmp[tmp.i], data);
		tmp.i--;
	}
}

void					ft_nowidthprec(t_data data, t_tmp tmp)
{
	if (*tmp.pt_sign)
	{
		ft_putchar(*tmp.pt_sign, data);
		ft_display(data, tmp);
	}
	else
		ft_display(data, tmp);
}

void					ft_noprecsignflags(t_data data, t_tmp tmp, int i)
{
	ft_putchar(*tmp.pt_sign, data);
	i = tmp.i;
	ft_display(data, tmp);
	while (*data.pt_width > (i + 1))
	{
		ft_putchar(' ', data);
		*data.pt_width -= 1;
	}
}

void					ft_noprecsignzero(t_data data, t_tmp tmp, char c)
{
	ft_putchar(*tmp.pt_sign, data);
	while (*data.pt_width > (tmp.i + 1))
	{
		ft_putchar(c, data);
		*data.pt_width -= 1;
	}
	ft_display(data, tmp);
}

void					ft_noprecsign(t_data data, t_tmp tmp, char c)
{
	while (*data.pt_width > (tmp.i + 1))
	{
		ft_putchar(c, data);
		*data.pt_width -= 1;
	}
	ft_putchar(*tmp.pt_sign, data);
	ft_display(data, tmp);
}
