#include "../includes/ft_printf.h"

void	parse(t_pf *pf)
{
	while (pf->format[pf->i])
	{
		print_text(pf);
		while (pf->format[pf->i] != '%' && pf->format[pf->i])
			pf->i++;
		if (pf->format[pf->i] == '%')
			get_stuff(pf);
		print_stuff(pf);
		reinit_struct(pf);
	}
}
