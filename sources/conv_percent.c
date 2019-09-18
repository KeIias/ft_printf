/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:11:53 by algautie          #+#    #+#             */
/*   Updated: 2019/09/18 17:17:58 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_percent(t_pf *pf)
{
	if (pf->width > 1)
	{
		pf->len += pf->width;
		if (pf->preflag_minus)
			write(1, "%", 1);
		while (--pf->width)
			write(1, " ", 1);
	}
	else
		pf->len++;
	if (!pf->preflag_minus)
		write(1, "%", 1);
}
