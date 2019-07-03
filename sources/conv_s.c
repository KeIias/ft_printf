/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:11:21 by algautie          #+#    #+#             */
/*   Updated: 2019/07/03 11:46:55 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_s(t_pf *pf)
{
	char	*arg;
	int		len;

	arg = (char*)va_arg(pf->args, char*);
	if (arg)
		len = ft_strlen((const char*)arg);
	else
		pf->error = 1;
	if (pf->error == 1)
		return ;
	if (pf->precision == -1)
		pf->precision = len;
	len = (len > pf->precision ? pf->precision : len);
	pf->len += len;
	pf->len += pf->width;
	if (pf->preflag_minus)
		write(1, arg, len > pf->precision ? pf->precision : len);
	while (pf->width-- > len)
		write(1, " ", 1);
	if (!pf->preflag_minus)
		write(1, arg, len > pf->precision ? pf->precision : len);
}
