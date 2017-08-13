/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:03:10 by agautier          #+#    #+#             */
/*   Updated: 2016/11/24 12:04:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t sf;

	i = 0;
	while (dst[i] && i < size)
		i++;
	sf = i;
	while (src[i - sf] && i < size - 1)
	{
		dst[i] = src[i - sf];
		i++;
	}
	if (sf < size)
		dst[i] = '\0';
	return (sf + ft_strlen(src));
}
