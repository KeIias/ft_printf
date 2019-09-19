/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:09:39 by algautie          #+#    #+#             */
/*   Updated: 2019/09/19 14:19:44 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_arg(t_pf *pf)
{
	unsigned long long arg;

	arg = (unsigned long long)va_arg(pf->args, void *);
	return (arg);
}

static void					print_width(t_pf *pf, char *str)
{
	char	c;
	int		len;

	len = (int)ft_strlen(str);
	if (str)
		len += 2;
	c = pf->preflag_zero ? '0' : ' ';
	while (pf->width > ft_biggest(pf->precision, len))
	{
		write(1, &c, 1);
		pf->width--;
		pf->len++;
	}
}

void						conv_p(t_pf *pf)
{
	char	*str;
	int		i;

	if (!(str = ft_ulltoa_base(get_arg(pf), 16)))
		pf->error = 1;
	if (pf->error)
		return ;
	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	pf->preflag_minus ? 0 : print_width(pf, str);
	if (str)
	{
		write(1, "0x", 2);
		pf->len += 2;
	}
	ft_putstr(str);
	pf->len += ft_strlen(str);
	pf->preflag_minus ? print_width(pf, str) : 0;
	if (str)
		free(str);
}
