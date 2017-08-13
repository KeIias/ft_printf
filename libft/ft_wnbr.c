/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:27:29 by agautier          #+#    #+#             */
/*   Updated: 2016/11/29 15:27:48 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function will count the ammount of words in an s string. Words are
** separated by the c char. The ammount of words will be returned as an int.
*/

int		ft_wnbr(const char *s, char c)
{
	int ctr;

	ctr = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			ctr++;
		while (*s != c && *s)
			s++;
	}
	return (ctr);
}
