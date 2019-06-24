#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_pf	*pf;
	int		len;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (-1);
	pf->format = format;
	if (format)
	{
		
	}
	len = pf->len;
	free(pf);
	return (len);
}
