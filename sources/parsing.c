/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:43:07 by algautie          #+#    #+#             */
/*   Updated: 2019/08/28 14:39:48 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse(t_pf *pf)
{
	while (pf->format[pf->i])
	{
		print_text(pf);
		while (pf->format[pf->i] != '%' && pf->format[pf->i])
			pf->i++;
		if (pf->format[pf->i] == '%')
		{
			get_stuff(pf);
			print_stuff(pf);
			reinit_struct(pf);
		}
	}
}
