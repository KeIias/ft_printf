/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:27:45 by agautier          #+#    #+#             */
/*   Updated: 2016/11/29 15:28:46 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		countlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(*tab) * (ft_wnbr((const char *)s, c) + 1));
	if (tab == NULL)
		return (NULL);
	n = ft_wnbr((const char*)s, c);
	while (n--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, countlen((const char *)s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + countlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
