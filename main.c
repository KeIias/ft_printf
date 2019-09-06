#include "includes/ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char c1 = 'e';
	char c2 = 'a';
	char *str1 = "bonjour";
	char *str2 = "amis";
	int d1 = 15;
	int d2 = -34;
	double f1 = 9.99;

	(void)ac;
	(void)c1;
	(void)c2;
	(void)str1;
	(void)str2;
	(void)d1;
	(void)d2;
	dprintf(1, av[1], f1);
	dprintf(1, "\n");
	ft_printf(av[1], f1);
	dprintf(1, "\n");
/*	dprintf(1, "### STRUCT CONTENT ###\n");
	dprintf(1, "+ = %d; - = %d; # = %d; zero = %d\n", pf->preflag_plus, pf->preflag_minus, pf->preflag_hash, pf->preflag_zero);
	dprintf(1, "width = %d\n", pf->width);
	dprintf(1, "precision = %d\n", pf->precision);
	dprintf(1, "flag = %d\n", pf->flag);
	dprintf(1, "conversion = %c\n", pf->conversion);
	dprintf(1, "len = %d\n", pf->len);
	dprintf(1, "######################\n");*/
	return (0);
}
