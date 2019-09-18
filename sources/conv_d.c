/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:15:55 by algautie          #+#    #+#             */
/*   Updated: 2019/09/18 17:26:36 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_arg(t_pf *pf)
{
	long long arg;

	if (pf->flag == NONE)
		arg = va_arg(pf->args, int);
	if (pf->flag == H)
		arg = (short)va_arg(pf->args, int);
	if (pf->flag == HH)
		arg = (char)va_arg(pf->args, int);
	if (pf->flag == L)
		arg = va_arg(pf->args, long);
	if (pf->flag == LL)
		arg = va_arg(pf->args, long long);
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
	char	c;
	int		len;

	len = (int)ft_strlen(str);
	if (ft_strchr(str, '-') != NULL)
		len--;
	if (pf->preflag_plus || ft_strchr(str, '-') != NULL || pf->preflag_space)
		pf->width--;
	c = pf->preflag_zero ? '0' : ' ';
	pf->preflag_zero ? print_sign(pf, str) : 0;
	while (pf->width > ft_biggest(pf->precision, len))
	{
		write(1, &c, 1);
		pf->width--;
		pf->len++;
	}
}

static void			print_precision(t_pf *pf, char *str)
{
	int len;
	int precision;

	precision = pf->precision;
	len = ft_strlen(str);
	if (ft_strchr(str, '-') != NULL)
		len--;
	pf->len += len;
	pf->preflag_zero ? 0 : print_sign(pf, str);
	if (pf->preflag_space && ft_strchr(str, '-') == NULL)
	{
		write(1, " ", 1);
		pf->len++;
	}
	while (precision > len)
	{
		write(1, "0", 1);
		pf->len++;
		precision--;
	}
	str[0] == '-' ? ft_putstr(str + 1) : ft_putstr(str);
}

void				conv_d(t_pf *pf)
{
	char *str;

	if (!(str = ft_lltoa_base(get_arg(pf), 10)))
		pf->error = 1;
	if (pf->error)
		return ;
	pf->preflag_minus == 1 ? print_precision(pf, str) : print_width(pf, str);
	pf->preflag_minus == 0 ? print_precision(pf, str) : print_width(pf, str);
	if (str)
		free(str);
}
