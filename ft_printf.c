/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:44:41 by agautier          #+#    #+#             */
/*   Updated: 2017/09/08 10:39:26 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(char *format, ...)
{
	int ret;
	t_printf *st;

	if (!format || !(struct_init(st)))
		return (-1);
	va_start(st->ap, format);
	ft_display(st, format);
	va_end(st->ap);
	//ret = /*ret*/
	//if (/*error*/)
		ret = -1;
	return (ret);
}

int main()
{
	char str[] = "bonjour%s wow";

	ft_printf(str);
	return (0);
}
