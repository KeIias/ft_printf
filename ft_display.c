/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 02:18:24 by agautier          #+#    #+#             */
/*   Updated: 2017/09/08 10:47:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_display(t_printf *st, const char *format)
{
	int j;

	st->i = -1;
	j = 0;
	while (format[++st->i] != '%' && format[st->i])
		write(1, &format[st->i], 1);
	if (format[st->i++] == '%')
	{
		ft_detect(st);
	}
	return (st);
}
