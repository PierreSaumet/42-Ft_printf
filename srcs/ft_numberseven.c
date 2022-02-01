/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberseven.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:28:31 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/08 18:28:32 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_lastelse(t_data data, t_tmp tmp, int i)
{
	if (!(tmp.i == 1 && tmp.tmp[0] == '0'))
	{
		while (i < (*data.pt_width - tmp.i - 1))
		{
			ft_putchar(' ', data);
			i++;
		}
		ft_putchar(*tmp.pt_sign, data);
		ft_display(data, tmp);
	}
	else
	{
		while (i < (*data.pt_width - *data.pt_prec - 1))
		{
			ft_putchar(' ', data);
			i++;
		}
		ft_putchar(*tmp.pt_sign, data);
	}
}
