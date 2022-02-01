/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:33:06 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:52:12 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file contains the functions used to calculate the qualificator,
**	the precision, the width and the flags. All function will return *fmt
**	because if the find something, they will increase it.
**	'ft_qual' for the qualificator.
**	'ft_prec' for the precision.
**	'ft_width' for the width.
**	'ft_flags' for the flags.
*/

const char			*ft_qual(const char *fmt, int *pt_qual)
{
	*pt_qual = -1;
	if (*fmt == 'h' || *fmt == 'l')
	{
		*pt_qual = *fmt;
		++fmt;
	}
	return (fmt);
}

const char			*ft_prec(const char *fmt, va_list args, t_data data)
{
	*data.pt_prec = -1;
	*data.pt_prec2 = -1;
	if (*fmt == '.')
	{
		++fmt;
		if (ft_isdigit(*fmt))
			*data.pt_prec = ft_turbo_atoi(&fmt);
		else if (*fmt == '*')
		{
			++fmt;
			*data.pt_prec = va_arg(args, int);
		}
		if (*data.pt_prec < 0)
		{
			data.prec2 = *data.pt_prec;
			*data.pt_prec2 = *data.pt_prec;
			*data.pt_prec = 0;
		}
	}
	return (fmt);
}

const char			*ft_width(const char *fmt, va_list args, t_data data)
{
	*data.pt_width = -1;
	if (ft_isdigit(*fmt))
		*data.pt_width = ft_turbo_atoi(&fmt);
	else if (*fmt == '*')
	{
		++fmt;
		*data.pt_width = va_arg(args, int);
		if (*data.pt_width < 0)
		{
			*data.pt_width = -*data.pt_width;
			*data.pt_flags |= LEFT;
		}
	}
	return (fmt);
}

const char			*ft_flags(const char *fmt, t_data data)
{
	while (*fmt && (*fmt == '-' || *fmt == '+' || *fmt == ' ' ||
			*fmt == '#' || *fmt == '0'))
	{
		if (*fmt == '-')
			*data.pt_flags |= LEFT;
		else if (*fmt == '+')
			*data.pt_flags |= PLUS;
		else if (*fmt == ' ')
			*data.pt_flags |= SPACE;
		else if (*fmt == '#')
			*data.pt_flags |= SPECIAL;
		else if (*fmt == '0')
		{
			if (*data.pt_flags == 16)
				break ;
			else
				*data.pt_flags |= ZERO;
		}
		fmt++;
	}
	return (fmt);
}
