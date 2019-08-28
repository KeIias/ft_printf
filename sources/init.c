/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:47:15 by algautie          #+#    #+#             */
/*   Updated: 2019/08/28 14:29:22 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_pf	*init_struct(t_pf *pf, const char *format)
{
	pf->format = format;
	pf->preflag_plus = 0;
	pf->preflag_minus = 0;
	pf->preflag_zero = 0;
	pf->preflag_hash = 0;
	pf->preflag_space = 0;
	pf->flag = NONE;
	pf->width = 0;
	pf->precision = -1;
	pf->error = 0;
	pf->cpy = (char*)format;
	pf->len = 0;
	pf->i = 0;
	pf->conv_pos = -1;
	pf->fd = -1;
	return (pf);
}

void	reinit_struct(t_pf *pf)
{
	pf->preflag_plus = 0;
	pf->preflag_minus = 0;
	pf->preflag_zero = 0;
	pf->preflag_hash = 0;
	pf->preflag_space = 0;
	pf->flag = NONE;
	pf->width = 0;
	pf->precision = -1;
}
