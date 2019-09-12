/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:54:56 by algautie          #+#    #+#             */
/*   Updated: 2019/09/12 16:03:50 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	round_nbr(t_pf *pf, char *str, long double nbr, long long int_part)
{
	int		i;
	char	beg;

	i = ft_strlen(str) - 2;
	beg = str[0];
	nbr *= 10;
	if (str[i + 1] >= '5')
	{
		str[i] = str[i] == '9' ? '0' : str[i] + 1;
		while (--i > -1 && str[i + 1] == '0')
			str[i] = str[i] == '9' ? '0' : str[i] + 1;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (beg == '9' && str[0] == '0' ? int_part + 1 : int_part);
}

char *get_fractional_part(t_pf *pf, long double nbr)
{
	int		i;
	char	*str;

	if (nbr < 0)
		nbr *= -1;
	if (pf->precision == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * pf->precision + 2);
	str[pf->precision + 1] = '\0';
	i = -1;
	while (++i <= pf->precision)
	{
		nbr *= 10;
		str[i] = (int)nbr + '0';
		nbr -= (int)nbr;
	}
	pf->len += ft_strlen(str);
	return (str);
}
