/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:47:02 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:52:29 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This file contains 3 functions to initialize the structures.
*/

void	ft_init_t_data(t_data *val)
{
	val->flags = 0;
	val->pt_flags = &val->flags;
	val->width = 0;
	val->pt_width = &val->width;
	val->prec = 0;
	val->pt_prec = &val->prec;
	val->qual = 0;
	val->pt_qual = &val->qual;
	val->count = 0;
	val->pt_count = &val->count;
	val->prec2 = 0;
	val->pt_prec2 = &val->prec2;
	return ;
}

void	ft_init_t(t_data *val)
{
	val->flags = 0;
	val->pt_flags = &val->flags;
	val->width = 0;
	val->pt_width = &val->width;
	val->prec = 0;
	val->pt_prec = &val->prec;
	val->qual = 0;
	val->pt_qual = &val->qual;
	val->prec2 = 0;
	val->pt_prec2 = &val->prec2;
}

void	ft_init_t_tmp(t_tmp *val)
{
	val->pt_c = &val->c;
	val->sign = 0;
	val->pt_sign = &val->sign;
	val->i = 0;
	val->pt_i = &val->i;
	val->res = 0;
	val->pt_res = &val->res;
	return ;
}
