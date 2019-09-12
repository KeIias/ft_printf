/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:56:27 by algautie          #+#    #+#             */
/*   Updated: 2019/09/12 16:54:28 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double get_arg(t_pf *pf)
{
	double arg;

	if (pf->flag == NONE || pf->flag == L)
		arg = va_arg(pf->args, double);
	if (pf->flag == BIG_L)
		arg = va_arg(pf->args, long double);
	return (arg);
}

static void			print_sign(t_pf *pf, char *str)
{
	if (ft_strchr(str, '-') != NULL)
	{
		write(1, "-", 1);
		pf->len++;
	}
	if (pf->preflag_plus && ft_strchr(str, '-') == NULL)
	{
		write(1, "+", 1);
		pf->len++;
	}
}

static void			print_width(t_pf *pf, char *str)
{
	char c;
	int len;

	len = (int)ft_strlen(str);
	if (ft_strchr(str, '-') != NULL)
		len--;
	if (pf->preflag_plus || ft_strchr(str, '-') != NULL || pf->preflag_space)
		pf->width--;
	c = pf->preflag_zero ? '0' : ' ';
	while (pf->width > ft_biggest(pf->precision, len))
	{
		write(1, &c, 1);
		pf->width--;
		pf->len++;
	}
}

static void			print_num(t_pf *pf, char *str, long double nbr)
{
	int		len;
	int		precision;
	char	c;

	precision = pf->precision;
	len = ft_strlen(str);
	pf->len += len;
	print_sign(pf, str);
	if (ft_strchr(str, '-') != NULL)
		len--;
	if (pf->preflag_space && ft_strchr(str, '-') == NULL)
	{
		write(1, " ", 1);
		pf->len++;
	}
	str[0] == '-' ? ft_putstr(str + 1) : ft_putstr(str);
	if (pf->preflag_hash || pf->precision > 0)
	{
		write(1, ".", 1);
		pf->len++;
	}
}

void				conv_f(t_pf *pf)
{
	long double	nbr;
	char		*str;
	char		*fractional_part;
	long long	int_part;

	nbr = get_arg(pf);
	int_part = (long long)nbr;
	fractional_part = NULL;
	if (!(str = ft_lltoa_base(int_part, 10)))
		pf->error = 1;
	if (pf->error)
		return ;
	if (pf->precision < 0)
		pf->precision = 6;
	if (pf->precision != 0)
		fractional_part = get_fractional_part(pf, nbr - (long long)nbr);
	int_part = round_nbr(pf, fractional_part, nbr, int_part);
	if (!(str = ft_lltoa_base(int_part, 10)))
		pf->error = 1;
	if (pf->error)
		return ;
	ft_putstr(str);
	ft_putchar('.');
	if (fractional_part)
		ft_putstr(fractional_part);
	if (fractional_part)
		free(fractional_part);
	//pf->preflag_minus == 1 ? print_num(pf,str, nbr) : print_width(pf, str);
	//pf->preflag_minus == 0 ? print_num(pf, str, nbr) : print_width(pf, str);
}