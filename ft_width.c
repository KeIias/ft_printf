#include "ft_printf.h"

void	ft_getwidth(t_printf *st, const char *format)
{
	int tmp;

	tmp = ft_atoi(&format[st->i]);
	while (ft_isdigit(format[st->i]))
		++st->i;
	st->width = tmp;
}
