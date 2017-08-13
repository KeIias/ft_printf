/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:53:15 by agautier          #+#    #+#             */
/*   Updated: 2016/11/26 21:59:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = ft_strlen((char*)s1);
	cpy = (char*)malloc((len + 1) * sizeof(*s1));
	if (cpy == NULL)
		return (0);
	cpy[len + 1] = '\0';
	while (i <= len)
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}
