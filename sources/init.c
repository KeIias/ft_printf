#include "../includes/ft_printf.h"

t_pf *init_struct(t_pf *pf, const char *format)
{
	pf->format = format;
	pf->flags = 0;
	pf->width = 0;
	pf->precision = 0;
	pf->cpy = (char*)format;
	pf->len = 0;
	pf->i = 0;
	pf->conv_pos = -1;
	pf->fd = -1;
	return (pf);
}
