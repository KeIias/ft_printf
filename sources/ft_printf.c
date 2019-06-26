#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_pf	*pf;
	int		len;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (-1);
	if (format)
	{
		init_struct(pf, format);
		va_start(pf->args, format);
		parse(pf);
		va_end(pf->args);
	}
	len = pf->len;
	free(pf);
	return (len);
}
