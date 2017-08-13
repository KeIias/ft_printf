#include "libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t n;

	n = 0;
	while (s && *s && *s != c)
	{
		s++;
		n++;
	}
	return (n);
}
