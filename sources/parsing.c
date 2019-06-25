#include "../includes/ft_printf.h"

void	parse(t_pf *pf)
{
	while (pf->format[pf->i])
	{
		while (pf->format[pf->i] != '%' && pf->format[pf->i])
			print_text(pf);
		if (pf->format[pf->i] == '%')
		{
			get_preflags(pf);
			get_width(pf);
			get_precision(pf);
			get_modifier(pf);
		}
	}
}
