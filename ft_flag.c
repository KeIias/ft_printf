#include "ft_printf.h"

void	ft_getflag(t_printf *st, const char *format)
{
	if (format[st->i] == '#')
		st->flags->pound = 1;
	if (format[st->i] == '+')
		st->flags->plus = 1;
	if (format[st->i] == '-')
		st->flags->minus = 1;
	if (format[st->i] == '0')
		st->flags->zero = 1;
	if (format[st->i] == ' ')
		st->flags->space = 1;
	++st->i;
}
