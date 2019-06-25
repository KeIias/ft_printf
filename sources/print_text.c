#include "../includes/ft_printf.h"

void print_text(t_pf *pf)
{
	ft_putstr("\n123\n");
	ft_putchar(pf->format[pf->i]);
	(pf->len)++;
	(pf->i)++;
}
