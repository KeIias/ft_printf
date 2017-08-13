/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:38:45 by agautier          #+#    #+#             */
/*   Updated: 2016/11/25 15:00:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t lenl;

	if (*little == '\0')
		return ((char*)big);
	lenl = ft_strlen(little);
	while (*big && len-- >= lenl)
	{
		if (*big == *little && ft_memcmp(big, little, lenl) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
