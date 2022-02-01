/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:47:02 by psaumet           #+#    #+#             */
/*   Updated: 2020/01/30 14:54:08 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <strings.h>
# include <stdarg.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

/*
**	Definition of the binary mask
**	ZERO is used for the '0' flag
**	SIGN is usef for the unsigned and signed long
**	PLUS is used for the '+' flag
**	SPACE is used for the ' ' flag
**	LEFT is used for the '-' flag
**	SPECIAL is used for the '#' flag
**	SMALL is used for 'abc' instead of upper characters
*/

# define ZERO		1
# define SIGN		2
# define PLUS		4
# define SPACE		8
# define LEFT		16
# define SMALL		32
# define SPECIAL	64

/*
**	This structure will be used to find the differents
**	flags, width, precision and qualification. it also
**	contains the pointers needed.
**	This structure will be mostly used by the files ft_conf.c,
**	ft_calculs.c and ft_flags.c.
*/

typedef struct		s_data
{
	int				flags;
	int				*pt_flags;
	int				width;
	int				*pt_width;
	int				prec;
	int				*pt_prec;
	int				prec2;
	int				*pt_prec2;
	int				qual;
	int				*pt_qual;
	int				count;
	int				*pt_count;
}					t_data;

/*
**	This structure will contains the variables
**	which are used mostly for the number's function,
**	the digits's function.
**	- 'tmp[66]' is a temporary variable necessary to
**	retrieve other information.
**	- 'c' is for the type of characters ('0' or ' ').
**	- 'sign' for the sign.
**	- 'i' for the index of tmp.
**	- all pointers needed.
*/

typedef struct		s_tmp
{
	char			tmp[66];
	char			*pt_tmp;
	char			c;
	char			*pt_c;
	char			sign;
	char			*pt_sign;
	char			locase;
	int				i;
	int				*pt_i;
	long int		res;
	long int		*pt_res;
	long int		cp_args;
}					t_tmp;

/*
**	Functions from 'ft_calculs.c'
*/
int					ft_strlen(const char *str);
long int			ft_do_div(unsigned long n, unsigned base);
long int			ft_do_mod(unsigned long n, unsigned base);

/*
**	Functions from 'ft_conv_cspp.c'
*/
void				ft_s(t_data data, va_list args);

/*
**	Functions from 'ft_conv_diuxx.c'
*/
void				ft_dui(const char *fmt, t_data data, va_list args);
void				ft_xx(const char *fmt, t_data data, va_list args);

/*
**	Functions from 'ft_convone.c'
*/
//void				ft_pourcentagewidth(t_data data, char c);
const char			*ft_pourcentage(const char *fmt, t_data data);
// void				ft_displayc(t_data data);
void				ft_c(t_data data, va_list args);
void				ft_sprec(t_data data, const char *s, int i, int len);

/*
**	Functions from 'ft_convthree.c'
*/
void				ft_elseiflen(t_data data, const char *s, int i, int len);
void				ft_sselseleft(t_data data, const char *s, char c, int len);
void				ft_elseif(t_data data, const char *s, char c, int len);

/*
**	Functions from 'ft_convtwo.c'
*/
void				ft_swidth(t_data data, const char *s, char c, int len);
void				ft_sselsesif(t_data data, const char *s, char c, int len);
void				ft_sselses(t_data data, const char *s, char c, int len);
void				ft_sselseleftprec(t_data data, const char *s, char c,
						int len);
void				ft_sselselefte(t_data data, const char *s, char c);

/*
**	Functions from 'ft_flags.c'
*/
const char			*ft_flags(const char *fmt, t_data data);
const char			*ft_width(const char *fmt, va_list args, t_data data);
const char			*ft_prec(const char *fmt, va_list args, t_data data);
const char			*ft_qual(const char *fmt, int *pt_qual);

/*
**	Functions from 'ft_init.c'
*/
void				ft_init_t_data(t_data *val);
void				ft_init_t_tmp(t_tmp *val);

/*
**	Functions from 'ft_libt.c'
*/
void				ft_putchar(char c, t_data data);
void				ft_putstr(char *str, t_data data);
int					ft_isdigit(int c);
int					ft_turbo_atoi(const char **str);

/*
** Function from 'ft_numbers.c'
*/
unsigned long		ft_flags_sign(t_tmp tmp, t_data data, long args);
void				ft_swif(t_data data, const char *s, char c, int len);
void				ft_selss(t_data data, const char *s, char c, int len);
void				ft_ssdisplay(t_data data, const char *s, int i);

/*
**	Functions from 'ft_numbersxone.c'
*/
void				ft_display(t_data data, t_tmp tmp);
void				ft_nowidthprec(t_data data, t_tmp tmp);
void				ft_noprecsignflags(t_data data, t_tmp tmp, int i);
void				ft_noprecsignzero(t_data data, t_tmp tmp, char c);
void				ft_noprecsign(t_data data, t_tmp tmp, char c);

/*
**	Functions from 'ft_numbersxtwo.c'
*/
void				ft_noprecnosignleft(t_data data, t_tmp tmp);
void				ft_noprecnosign(t_data data, t_tmp tmp, char c);
void				ft_noprec(t_data data, t_tmp tmp, int i, char c);
void				ft_nowsignprec(t_data data, t_tmp tmp);
void				ft_nowsign(t_data data, t_tmp tmp);

/*
**	Functions from 'ft_numbersxthree.c'
*/
void				ft_nownosignprec(t_data data, t_tmp tmp);
void				ft_nowidth(t_data data, t_tmp tmp);
void				ft_elseflagsleft(t_data data, t_tmp tmp, int i, char c);
void				ft_elseflagsnoleft(t_data data, t_tmp tmp, int i);
void				ft_elsenoprec(t_data data, t_tmp tmp, int i, char c);

/*
**	Functions from 'ft_numbersxfour.c'
*/
void				ft_elsenoprecend(t_data data, t_tmp tmp, int i);
void				ft_elsenosignleft(t_data data, t_tmp tmp, int i);
void				ft_elsenosignleftno(t_data data, t_tmp tmp, int i);
void				ft_elsenosignwidthup(t_data data, t_tmp tmp, int i,
						char c);
void				ft_elsewidthprec(t_data data, t_tmp tmp, int i);

/*
**	Functions from 'ft_numberxfive.c'
*/
void				ft_elseelse(t_data data, t_tmp tmp, int i);
void				ft_elsesignelseelse(t_data data, t_tmp tmp, int i);
void				ft_elsesignleftelse(t_data data, t_tmp tmp, int i);
void				ft_elsesignelseleftprec(t_data data, t_tmp tmp);
void				ft_elsesignelse(t_data data, t_tmp tmp, int i);

/*
**	Functions from 'ft_numberssix.c'
*/
void				ft_elsesignleft(t_data data, t_tmp tmp, int i);
void				ft_las(t_data data, t_tmp tmp, int i, char c);
void				ft_elsesignleftelseif(t_data data, t_tmp tmp, int i,
						char c);
void				ft_elsesignleftelses(t_data data, t_tmp tmp, int i,
						char c);
void				ft_elsesignelses(t_data data, t_tmp tmp, int i);

/*
**	Functions from 'ft_numbersx.c'
*/
void				ft_elsefirst(t_data data, t_tmp tmp, int i, char c);
void				ft_else(t_data data, t_tmp tmp, int i, char c);
void				ft_domath(t_data data, t_tmp tmp);
void				ft_numberxa(long args, int base, t_data data);
void				ft_numberx(long args, int base, t_data data);

/*
**	Functions from 'ft_numberseven.c'
*/
void				ft_lastelse(t_data data, t_tmp tmp, int i);

/*
**	Functions from 'ft_p_next.c'
*/
void				ft_digits_p_display(t_data data, t_tmp tmp);
void				ft_digits_p_no_f(t_data data, t_tmp tmp, char c, int i);

/*
**	Functions from 'ft_p.c'
*/
void				ft_p(t_data data, va_list args);
void				ft_num_p_prec(t_data data, t_tmp tmp);
void				ft_number_p(long args, int base, t_data data);
void				ft_digits_p_next(t_data data, t_tmp tmp, char c, int i);
void				ft_digits_p(long args, int base, t_data data, t_tmp tmp);

/*
**	Functions from 'ft_printf.c'
*/
int					ft_printf(const char *fmt, ...);

#endif
