/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:04:40 by algautie          #+#    #+#             */
/*   Updated: 2019/06/25 12:10:49 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_width_precision(t_pf *pf)
{
	if (ft_isdigit(pf->format[pf->i]))
	{
		pf->width = ft_isolate_number(pf->cpy, pf->i);
		while (ft_isdigit(pf->format[pf->i]))
			++(pf->i);
	}
	if (pf->format[pf->i] == '.')
	{
		++(pf->i);
		if (ft_isdigit(pf->format[pf->i]))
		{
			pf->precision = ft_isolate_number(pf->cpy, pf->i);
			while (ft_isdigit(pf->format[pf->i]))
				++(pf->i);
		}
	}
}

static void	get_flags(t_pf *pf)
{
	while (ft_cmpchars(pf->format[++(pf->i)], "+-#0"))
	{
		pf->flags = pf->format[pf->i] == '+' ? pf->flags + F_PLUS : pf->flags;
		pf->flags = pf->format[pf->i] == '-' ? pf->flags + F_MINUS : pf->flags;
		pf->flags = pf->format[pf->i] == '#' ? pf->flags + F_HASH : pf->flags;
		pf->flags = pf->format[pf->i] == '0' ? pf->flags + F_ZERO : pf->flags;
	}
}

void		get_stuff(t_pf *pf)
{
	get_flags(pf);
	get_width_precision(pf);
}
