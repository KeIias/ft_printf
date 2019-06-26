#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int n;

	n = atoi(av[2]);
	printf(av[1], n);
	printf("%2147483647.4d", 12);
	return (0);
}
