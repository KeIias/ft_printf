/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:54:56 by algautie          #+#    #+#             */
/*   Updated: 2019/08/29 17:29:21 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	round(char *str, long double nbr)
{
	int i;

	i = ft_strlen(str) - 1;
	nbr *= 10;
	if ((int)nbr >= 5)
	{
		str[i] = str[i] == '9' ? '0' : str[i] + 1;
		while (--i > -1 && str[i + 1] == '0')
			str[i] = str[i] == '9' ? '0' : str[i] + 1;
	}
}

void		print_fractional_part(t_pf *pf, long double nbr)
{
	int		i;
	char	*str;

	if (nbr < 0)
		nbr *= -1;
	if (pf->preflag_hash || pf->precision > 0)
	{
		write(1, ".", 1);
		pf->len++;
	}
	else if (pf->precision == 0)
		return ;
	str = (char *)malloc(sizeof(char) * pf->precision + 1);
	str[pf->precision] = '\0';
	i = -1;
	while (++i != pf->precision)
	{
		nbr *= 10;
		str[i] = (int)nbr + '0';
		nbr -= (int)nbr;
	}
	round(str, nbr);
	pf->len += ft_strlen(str);
	ft_putstr(str);
	free(str);
}
