/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:04:40 by algautie          #+#    #+#             */
/*   Updated: 2019/07/08 16:25:18 by algautie         ###   ########.fr       */
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
	long tmp;

	if (ft_isdigit(pf->format[pf->i]))
	{
		tmp = ft_isolate_number(pf->cpy, pf->i);
		pf->width = tmp > MAX_RANGE ? 0 : tmp;
		while (ft_isdigit(pf->format[pf->i]))
			++(pf->i);
	}
	if (pf->format[pf->i] == '.')
	{
		++(pf->i);
		if (ft_isdigit(pf->format[pf->i]))
		{
			tmp = ft_isolate_number(pf->cpy, pf->i);
			pf->precision = tmp > MAX_RANGE ? 0 : tmp;
			while (ft_isdigit(pf->format[pf->i]))
				++(pf->i);
		}
	}
}

static void	get_flags(t_pf *pf)
{
	while (ft_cmpchars(pf->format[++(pf->i)], "+-#0 "))
	{
		pf->preflag_plus = pf->format[pf->i] == '+' ? 1 : pf->preflag_plus;
		pf->preflag_minus = pf->format[pf->i] == '-' ? 1 : pf->preflag_minus;
		pf->preflag_hash = pf->format[pf->i] == '#' ? 1 : pf->preflag_hash;
		pf->preflag_zero = pf->format[pf->i] == '0' ? 1 : pf->preflag_zero;
		pf->preflag_space = pf->format[pf->i] == ' ' ? 1 : pf->preflag_space;
	}
}

void		get_stuff(t_pf *pf)
{
	get_flags(pf);
	get_width_precision(pf);
	get_flag(pf);
	get_conversion(pf);
}
