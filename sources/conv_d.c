/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:15:55 by algautie          #+#    #+#             */
/*   Updated: 2019/07/03 15:48:08 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_arg(t_pf *pf)
{
	long long arg;

	if (pf->flag == NONE)
		arg = va_arg(pf->args, int);
	if (pf->flag == H)
		arg = (char)va_arg(pf->args, int);
	if (pf->flag == HH)
		arg = (short)va_arg(pf->args, int);
	if (pf->flag == L)
		arg = va_arg(pf->args, long);
	if (pf->flag == LL)
		arg = va_arg(pf->args, long long);
	return (arg);
}

void			conv_d(t_pf *pf)
{
	char *str;

	if (!(str = ft_lltoa_base(get_arg(pf), 10)))
		pf->error = 1;
	if (pf->error)
		return ;
	
}
