/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:29:14 by algautie          #+#    #+#             */
/*   Updated: 2019/09/18 16:29:15 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_arg(t_pf *pf)
{
	unsigned long long arg;

	if (pf->flag == NONE)
		arg = va_arg(pf->args, unsigned int);
	if (pf->flag == H)
		arg = (unsigned short)va_arg(pf->args, unsigned int);
	if (pf->flag == HH)
		arg = (unsigned char)va_arg(pf->args, unsigned int);
	if (pf->flag == L)
		arg = va_arg(pf->args, unsigned long);
	if (pf->flag == LL)
		arg = va_arg(pf->args, unsigned long long);
	return (arg);
}

static void					print_width(t_pf *pf, char *str)
{
	char	c;
	int		len;

	len = (int)ft_strlen(str);
	c = pf->preflag_zero ? '0' : ' ';
	while (pf->width > ft_biggest(pf->precision, len + pf->preflag_hash))
	{
		write(1, &c, 1);
		pf->width--;
		pf->len++;
	}
}

static void					print_precision(t_pf *pf, char *str)
{
	int len;
	int precision;

	precision = pf->precision;
	len = ft_strlen(str);
	pf->len += len;
	if (pf->preflag_hash && !(pf->width > ft_biggest(pf->precision, len)
			&& pf->preflag_zero))
	{
		write(1, "0", 1);
		precision--;
		pf->len++;
	}
	while (precision > len)
	{
		write(1, "0", 1);
		pf->len++;
		precision--;
	}
	ft_putstr(str);
}

void						conv_b(t_pf *pf)
{
	char *str;

	if (!(str = ft_ulltoa_base(get_arg(pf), 2)))
		pf->error = 1;
	if (pf->error)
		return ;
	if (str[0] == '0')
		pf->preflag_hash = 0;
	pf->preflag_minus == 1 ? print_precision(pf, str) : print_width(pf, str);
	pf->preflag_minus == 0 ? print_precision(pf, str) : print_width(pf, str);
	if (str)
		free(str);
}
