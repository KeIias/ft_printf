/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:43:23 by algautie          #+#    #+#             */
/*   Updated: 2019/07/03 11:43:37 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_text(t_pf *pf)
{
	int len;

	len = ft_strcdlen(pf->cpy, '%', pf->i);
	write(1, pf->format + pf->i, len);
	pf->len += len;
	pf->i += len;
}
