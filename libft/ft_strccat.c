#include "libft.h"

char	*ft_strccat(char *dest, const char *src, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
		while (src[j] && src[j] != c)
			dest[i++] = src[j++];
		dest[i] = '\0';
	return (dest);
}
