/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:43:07 by algautie          #+#    #+#             */
/*   Updated: 2019/09/18 14:49:31 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	remove_conflicts(t_pf *pf)
{
	if (pf->preflag_plus && pf->preflag_space)
		pf->preflag_space = 0;
	if (pf->preflag_zero && pf->preflag_minus)
		pf->preflag_zero = 0;
	if (pf->preflag_zero && ft_cmpchars(pf->conversion, "diouxX") \
			&& pf->precision > 0)
		pf->preflag_zero = 0;
}

void		parse(t_pf *pf)
{
	while (pf->format[pf->i])
	{
		print_text(pf);
		while (pf->format[pf->i] != '%' && pf->format[pf->i])
			pf->i++;
		if (pf->format[pf->i] == '%')
		{
			get_stuff(pf);
			remove_conflicts(pf);
			print_stuff(pf);
			reinit_struct(pf);
		}
	}
}
