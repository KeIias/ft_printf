/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:44:41 by agautier          #+#    #+#             */
/*   Updated: 2017/08/11 04:45:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	int ret;

	if (!format /*|| failed to init*/)
		return (-1);
	//va_start(/*???*/, format);
	ft_display(format);
	//va_end(/*???*/);
	//ret = /*ret*/
	//if (/*error*/)
		ret = -1;
	return (ret);
}

int main ()
{
	char str[] = "bonjour%s wow";

	ft_printf(str);
	return (0);
}
