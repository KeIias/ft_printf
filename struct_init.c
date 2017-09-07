/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:12:20 by agautier          #+#    #+#             */
/*   Updated: 2017/09/07 22:28:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*struct_init(t_printf *st)
{
	if (!(st = ft_memalloc(sizeof(t_printf)))
		|| !(st->flags = ft_memalloc(sizeof(t_flags))))
		exit(-1);
	st->i = 0;
	st->ret = 0;
	return (st);
}
