/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 02:18:24 by agautier          #+#    #+#             */
/*   Updated: 2017/09/17 06:33:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_detect(t_printf *st, const char *format)
{
	while (format[st->i] && !(ft_strrchr(("sDpdDioOuUxXcC%"), format[st->i])))
	{
		if (ft_strrchr("#0-+", format[st->i]))
			//flag
		else if ((format[st->i] != "0" && ft_isidigit((int)format[st->i]))
				|| format[st->i] == "*")
			//width
		else if (format[st->i] == ".")
			//precision
		else if (ft_strrchr("hljz", format[st->i]))
			//modifier
		else
			break;
	}
	//converter
	return (st);
}

t_printf		*ft_display(t_printf *st, const char *format)
{
	int j;

	st->i = -1;
	j = 0;
	while (format[++st->i] != '%' && format[st->i])
		write(1, &format[st->i], 1);
	if (format[st->i++] == '%')
		st = ft_detect(st, format);
	return (st);
}
