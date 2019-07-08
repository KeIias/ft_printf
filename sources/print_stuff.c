/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:11:52 by algautie          #+#    #+#             */
/*   Updated: 2019/07/08 14:07:15 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_stuff(t_pf *pf)
{
	pf->conversion == 'c' ? conv_c(pf) : 0;
	pf->conversion == 's' ? conv_s(pf) : 0;
	pf->conversion == 'd' || pf->conversion == 'i' ? conv_d(pf) : 0;
}
