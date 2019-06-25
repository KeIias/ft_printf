/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:04:40 by algautie          #+#    #+#             */
/*   Updated: 2019/06/25 17:57:24 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_flag(t_pf *pf)
{
	if (ft_cmpchars(pf->format[pf->i], "Lhl"))
	{
		pf->flag = pf->format[pf->i] == 'L' ? BIG_L : pf->flag;
		pf->flag = pf->format[pf->i] == 'h' ? H : pf->flag;
		pf->flag = pf->format[pf->i] == 'l' ? L : pf->flag;
		(pf->i)++;
	}
	if (ft_cmpchars(pf->format[pf->i], "hl"))
	{
		pf->flag = pf->format[pf->i] == 'h' && pf->flag == H ? HH : pf->flag;
		pf->flag = pf->format[pf->i] == 'l' && pf->flag == L ? LL : pf->flag;
		(pf->i)++;
	}
}

static void	get_conversion(t_pf *pf)
{
	if (ft_cmpchars(pf->cpy[pf->i], "cspdiouxXf%"))
	{
		pf->conversion = pf->format[pf->i];
		(pf->i)++;
	}
}

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
	get_flag(pf);
	get_conversion(pf);
}
