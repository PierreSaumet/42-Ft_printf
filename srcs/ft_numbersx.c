/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbersx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:43:47 by psaumet           #+#    #+#             */
/*   Updated: 2020/02/07 15:43:49 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_elsefirst(t_data data, t_tmp tmp, int i, char c)
{
	if (*data.pt_flags & LEFT)
	{
		i = tmp.i;
		if (*data.pt_prec > tmp.i)
			ft_elsesignleft(data, tmp, i);
		else if (*data.pt_prec < tmp.i)
			ft_elsesignleftelseif(data, tmp, i, c);
		else
			ft_elsesignleftelses(data, tmp, i, c);
	}
	else
	{
		if (*data.pt_prec > tmp.i)
			ft_elsesignelses(data, tmp, i);
		else
			ft_lastelse(data, tmp, i);
	}
}

void					ft_else(t_data data, t_tmp tmp, int i, char c)
{
	if (*tmp.pt_sign)
	{
		if ((tmp.i + 1) < *data.pt_width)
			ft_elsefirst(data, tmp, i, c);
		else
			ft_elsesignelse(data, tmp, i);
	}
	else
	{
		if (*data.pt_width > *data.pt_prec)
			ft_elsenosignwidthup(data, tmp, i, c);
		else if (*data.pt_width == *data.pt_prec)
			ft_elsewidthprec(data, tmp, i);
		else
			ft_elseelse(data, tmp, i);
	}
}

void					ft_domath(t_data data, t_tmp tmp)
{
	char				c;
	int					i;

	i = 0;
	c = ' ';
	if (*data.pt_flags & ZERO)
		c = '0';
	if (*data.pt_width == -1 && *data.pt_prec == -1)
		ft_nowidthprec(data, tmp);
	else if (*data.pt_width >= 0 && *data.pt_prec == -1)
		ft_noprec(data, tmp, i, c);
	else if (*data.pt_width == -1 && *data.pt_prec >= 0)
		ft_nowidth(data, tmp);
	else
		ft_else(data, tmp, i, c);
}

void					ft_numberxa(long args, int base, t_data data)
{
	t_tmp				tmp;
	char				*digits;

	digits = "0123456789ABCDEF";
	ft_init_t_tmp(&tmp);
	args = ft_flags_sign(tmp, data, args);
	tmp.locase = (*data.pt_flags & SMALL);
	if (args != 0)
	{
		while (args != 0)
		{
			tmp.res = (digits[ft_do_mod(args, base)] | tmp.locase);
			args = ft_do_div(args, base);
			tmp.tmp[tmp.i] = tmp.res;
			tmp.i++;
		}
	}
	else
	{
		tmp.tmp[tmp.i] = '0';
		tmp.i++;
	}
	ft_domath(data, tmp);
}

void					ft_numberx(long args, int base, t_data data)
{
	t_tmp				tmp;
	char				*digits;

	digits = "0123456789ABCDEF";
	ft_init_t_tmp(&tmp);
	args = ft_flags_sign(tmp, data, args);
	tmp.locase = (*data.pt_flags & SMALL);
	if (args != 0)
	{
		while (args != 0)
		{
			tmp.res = (digits[ft_do_mod(args, base)]);
			args = ft_do_div(args, base);
			tmp.tmp[tmp.i] = tmp.res;
			tmp.i++;
		}
	}
	else
	{
		tmp.tmp[tmp.i] = '0';
		tmp.i++;
	}
	ft_domath(data, tmp);
}
