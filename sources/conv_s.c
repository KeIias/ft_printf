/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:11:21 by algautie          #+#    #+#             */
/*   Updated: 2019/09/19 12:24:27 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_s(t_pf *pf)
{
	char	*arg;
	int		len;
	char	*nothing;

	arg = (char*)va_arg(pf->args, char*);
	nothing = (arg ? NULL : ft_strdup("(null)"));
	if (!arg)
		arg = nothing;
	len = ft_strlen((const char*)arg);
	if (pf->precision == -1)
		pf->precision = len;
	if (pf->is_prec == 0)
		pf->precision = 0;
	pf->len += len > pf->precision ? pf->precision : len;
	if (pf->preflag_minus)
		write(1, arg, len > pf->precision ? pf->precision : len);
	while (pf->width-- > (len > pf->precision ? pf->precision : len))
	{
		write(1, " ", 1);
		pf->len++;
	}
	if (!pf->preflag_minus)
		write(1, arg, len > pf->precision ? pf->precision : len);
	if (nothing)
		free(nothing);
}
