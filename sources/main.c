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
	dprintf(1, "+ = %d; - = %d; # = %d; zero = %d\n", pf->flag_plus, pf->flag_minus, pf->flag_hash, pf->flag_zero);
	dprintf(1, "width = %d\n", pf->width);
	dprintf(1, "precision = %d\n", pf->precision);
	dprintf(1, "flag = %d\n", pf->flag);
	dprintf(1, "conversion = %c\n", pf->conversion);
	dprintf(1, "len = %d\n", pf->len);
	dprintf(1, "######################\n");
	return (0);
}
