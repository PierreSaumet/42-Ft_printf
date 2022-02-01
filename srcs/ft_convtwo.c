/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:59:29 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/08 17:59:30 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_swidth(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_width <= len)
		ft_putstr((char *)s, data);
	else if (*data.pt_flags & LEFT)
	{
		if (*data.pt_width > len)
		{
			ft_putstr((char *)s, data);
			while (i < (*data.pt_width - len))
			{
				ft_putchar(c, data);
				i++;
			}
		}
	}
	else if (*data.pt_width > len)
		ft_swif(data, s, c, len);
}

void				ft_sselsesif(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_prec >= len)
	{
		while (i < (*data.pt_width - len))
		{
			ft_putchar(c, data);
			i++;
		}
		ft_putstr((char *)s, data);
	}
	else
	{
		ft_selss(data, s, c, len);
	}
}

void				ft_sselses(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_prec == 0)
	{
		while (i < *data.pt_width)
		{
			ft_putchar(c, data);
			i++;
		}
	}
	else if (*data.pt_prec < *data.pt_width)
	{
		ft_sselsesif(data, s, c, len);
	}
}

void				ft_sselseleftprec(t_data data, const char *s, char c,
						int len)
{
	int				i;

	i = 0;
	if (len < *data.pt_width && *data.pt_prec2 != -1)
	{
		ft_putstr((char *)s, data);
		i = len;
		while (i < *data.pt_width)
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

void				ft_sselselefte(t_data data, const char *s, char c)
{
	int				i;

	i = 0;
	while (i < *data.pt_prec)
	{
		ft_putchar(*(char *)s, data);
		i++;
		s++;
	}
	i = 0;
	while (i < (*data.pt_width - *data.pt_prec))
	{
		ft_putchar(c, data);
		i++;
	}
}
