#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	t_pf *pf;
	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (-1);
	init_struct(pf, av[1]);
	parse(pf);
	dprintf(1, "### STRUCT CONTENT ###\n");
	dprintf(1, "flags = %d\n", pf->flags);
	dprintf(1, "width = %d\n", pf->width);
	dprintf(1, "precision = %d\n", pf->precision);
	dprintf(1, "conversion = %c\n", pf->conversion);
	dprintf(1, "######################\n");
	return (0);
}
