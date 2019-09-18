/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:11:52 by algautie          #+#    #+#             */
/*   Updated: 2019/09/18 16:15:12 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_stuff(t_pf *pf)
{
	pf->conversion == 'c' ? conv_c(pf) : 0;
	pf->conversion == 's' ? conv_s(pf) : 0;
	pf->conversion == 'o' ? conv_o(pf) : 0;
	pf->conversion == 'u' ? conv_u(pf) : 0;
	pf->conversion == 'p' ? conv_p(pf) : 0;
	pf->conversion == 'f' ? conv_f(pf) : 0;
	pf->conversion == 'b' ? conv_b(pf) : 0;
	pf->conversion == '%' ? conv_percent(pf) : 0;
	pf->conversion == 'd' || pf->conversion == 'i' ? conv_d(pf) : 0;
	pf->conversion == 'x' || pf->conversion == 'X' ? conv_x(pf) : 0;
}
