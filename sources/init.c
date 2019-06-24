#include "../includes/ft_printf.h"

t_pf *init_struct(t_pf *pf, const char* format)
{
	pf->format = format;
	pf->cpy = (char*)format;
	pf->len = 0;
	pf->i = 0;
	pf->conv_pos = 0;
	pf->fd = 1;
	return (pf);
}
