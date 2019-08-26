#include "../includes/ft_printf.h"

void	conv_percent(t_pf *pf)
{
	if (pf->width > 1)
	{
		pf->len += pf->width;
		if (pf->preflag_minus)
			write(1, "%", 1);
		while (--pf->width)
			write(1, " ", 1);
	}
	if (!pf->preflag_minus)
		write(1, "%", 1);
}
