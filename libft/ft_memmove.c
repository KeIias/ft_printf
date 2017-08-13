/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:29:32 by agautier          #+#    #+#             */
/*   Updated: 2016/11/26 18:43:11 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*psrc;
	char	*pdst;

	i = 0;
	psrc = (char *)src;
	pdst = (char *)dst;
	if (psrc < pdst)
	{
		while (len--)
		{
			pdst[len] = psrc[len];
		}
	}
	else
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	return (dst);
}
