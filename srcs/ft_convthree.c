/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convthree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:59:20 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/08 17:59:21 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_elseif(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_prec < len)
		ft_elseiflen(data, s, i, len);
	else if (*data.pt_prec > len)
	{
		while (i < (*data.pt_width - len))
		{
			ft_putchar(c, data);
			i++;
		}
		ft_putstr((char *)s, data);
	}
	else
		ft_putstr((char *)s, data);
}

void				ft_sselseleft(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_prec == 0)
		ft_sselseleftprec(data, s, c, len);
	else if (*data.pt_prec < *data.pt_width)
	{
		if (*data.pt_prec >= len)
		{
			ft_putstr((char *)s, data);
			while (i < (*data.pt_width - len))
			{
				ft_putchar(c, data);
				i++;
			}
		}
		else
			ft_sselselefte(data, s, c);
	}
}

void				ft_elseiflen(t_data data, const char *s, int i, int len)
{
	if (*data.pt_prec == 0 && -*data.pt_prec2 == len)
	{
		ft_putstr((char *)s, data);
	}
	else
	{
		while (i < *data.pt_prec)
		{
			ft_putchar(*(char *)s, data);
			i++;
			s++;
		}
	}
}
