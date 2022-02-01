/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cspp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:48:12 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:51:49 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			ft_ssprecelse(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_flags & LEFT)
	{
		ft_putstr((char *)s, data);
		while (i < (*data.pt_width - len))
		{
			ft_putchar(c, data);
			i++;
		}
	}
	else
	{
		while (i < (*data.pt_width - len))
		{
			ft_putchar(c, data);
			i++;
		}
		ft_putstr((char *)s, data);
	}
	return ;
}

static void			ft_ss(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_prec > *data.pt_width)
	{
		if (*data.pt_prec <= len)
			ft_ssdisplay(data, s, i);
		else
			ft_ssprecelse(data, s, c, len);
	}
	else if (*data.pt_prec == *data.pt_width)
		ft_elseif(data, s, c, len);
	else
	{
		if (*data.pt_flags & LEFT)
			ft_sselseleft(data, s, c, len);
		else
			ft_sselses(data, s, c, len);
	}
	return ;
}

static void			ft_snull(t_data data, int i, char c)
{
	while (i < *data.pt_width)
	{
		ft_putchar(c, data);
		i++;
	}
	return ;
}

static void			ft_selseif(t_data data, const char *s, char c, int len)
{
	int				i;

	i = 0;
	if (*data.pt_width == -1 && *data.pt_prec == -1)
		ft_putstr((char *)s, data);
	else if (*data.pt_width == -1 && *data.pt_prec >= 0)
		ft_sprec(data, s, i, len);
	else if (*data.pt_width >= 0 && *data.pt_prec == -1)
		ft_swidth(data, s, c, len);
	else
		ft_ss(data, s, c, len);
	return ;
}

void				ft_s(t_data data, va_list args)
{
	int				len;
	const char		*s;
	int				i;
	char			c;

	len = 0;
	s = va_arg(args, char *);
	i = 0;
	c = ' ';
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (*data.pt_flags & ZERO)
		c = '0';
	if (len == 0)
		ft_snull(data, i, c);
	else if (len > 0)
		ft_selseif(data, s, c, len);
	return ;
}
