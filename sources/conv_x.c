/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:21:06 by algautie          #+#    #+#             */
/*   Updated: 2019/08/21 16:17:07 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_arg(t_pf *pf)
{
	unsigned long long arg;

	if (pf->flag == NONE)
		arg = va_arg(pf->args, unsigned int);
	if (pf->flag == H)
		arg = (unsigned char)va_arg(pf->args, unsigned int);
	if (pf->flag == HH)
		arg = (unsigned short)va_arg(pf->args, unsigned int);
	if (pf->flag == L)
		arg = va_arg(pf->args, unsigned long);
	if (pf->flag == LL)
		arg = va_arg(pf->args, unsigned long long);
	return (arg);
}

static void			print_width(t_pf *pf, char *str)
{
	char	c;
	int		len;

	len = (int)ft_strlen(str);
	c = pf->preflag_zero ? '0' : ' ';
	while (pf->width > ft_biggest(pf->precision, len) + (pf->preflag_hash * 2))
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
	pf->len += len;
	if (pf->preflag_hash)
	{
		write(1, "0", 1);
		write(1, &(pf->conversion), 1);
		pf->len += 2;
	}
	while (precision > len)
	{
		write(1, "0", 1);
		pf->len++;
		precision--;
	}
	ft_putstr(str);
}

void				conv_x(t_pf *pf)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = ft_ulltoa_base(get_arg(pf), 16)))
		pf->error = 1;
	if (pf->error)
		return ;
	if (pf->conversion == 'x')
		while (str[++i])
			str[i] = ft_tolower(str[i]);
	pf->preflag_minus == 1 ? print_precision(pf, str) : print_width(pf, str);
	pf->preflag_minus == 0 ? print_precision(pf, str) : print_width(pf, str);
}
