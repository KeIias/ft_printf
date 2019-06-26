#include "../includes/ft_printf.h"

void print_text(t_pf *pf)
{
	int len;

	len = ft_strcdlen(pf->cpy, '%', pf->i);
	write(1, pf->format + pf->i, len);
	pf->len += len;
	pf->i += len;
}
