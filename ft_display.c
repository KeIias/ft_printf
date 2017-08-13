/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 02:18:24 by agautier          #+#    #+#             */
/*   Updated: 2017/08/11 03:54:33 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display(char *format)
{
	int i;
	int j;
	char *str;

	i = -1;
	j = 0;
	while (format[++i] != '%' && format[i] != '\0')
		ft_putchar(format[i]);
	if (format[i] == '%')
	{
		while (format[++i] >= 'A' && format[i] <= 'z')
			str[j] = format[i];
		ft_detect(str);
	}
	return (0);
}
