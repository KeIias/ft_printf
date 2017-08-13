/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:04:51 by agautier          #+#    #+#             */
/*   Updated: 2016/11/27 05:11:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	char	*str;

	if (*little == '\0')
		return ((char*)big);
	i = ft_strlen(little);
	str = (char *)big;
	while (*str)
	{
		if (*str == *little && ft_memcmp(str, little, i) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
