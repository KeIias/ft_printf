/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:26:03 by agautier          #+#    #+#             */
/*   Updated: 2016/11/27 04:33:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		negative_n(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

static char		*convert(int n)
{
	int		m;
	int		neg;
	int		len;
	char	*str;

	m = n;
	len = 2;
	neg = 0;
	negative_n(&n, &neg);
	len += neg;
	while (m /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char *str;

	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		ft_strcpy(str, "-2147483648");
	}
	else
		str = convert(n);
	return (str);
}
