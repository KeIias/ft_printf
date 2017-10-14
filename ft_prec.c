#include "ft_printf.h"

void	ft_getprec(t_printf *st, const char *format)
{
	int tmp;

	++st->i;
	tmp = ft_atoi(&format[st->i]);
	while (format[st->i] == '0')
		++st->i;
	if (!ft_isdigit(format[st->i]))
		return ;
	st->prec = tmp;
}
