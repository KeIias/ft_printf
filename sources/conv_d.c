/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:15:55 by algautie          #+#    #+#             */
/*   Updated: 2019/07/03 16:56:04 by algautie         ###   ########.fr       */
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

static void			print_prec_width(t_pf *pf, char str)
{
	char c;

	if (pf->preflag_plus && ft_strchr(str, '-') != NULL)
		pf->len++;
	if (!pf->preflag_minus)
	{
		
	}
}

void				conv_d(t_pf *pf)
{
	char *str;

	if (!(str = ft_lltoa_base(get_arg(pf), 10)))
		pf->error = 1;
	if (pf->error)
		return ;
	pf->len = ft_strlen(str);
	print_prec_width(pf, str);
}
