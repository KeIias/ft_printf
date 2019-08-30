#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./includes/ft_printf.h"

void	print_bits(unsigned char oct)
{
	 int i = 128;

	while (i > 0)
	{
		if (i & oct)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i /= 2;
	}
	write(1, " ", 1);
}

int main(int ac, char **av)
{
	float f1, f2, f3, f4;
	unsigned int mask = 1;
	unsigned char *str;

	f4 = -0;
	str = (unsigned char*)malloc(sizeof(unsigned char) * sizeof(float));
	ft_memcpy(str, &f4, sizeof(float));
	/*if (str[0] & 128)
		printf("Y");
	else
		printf("N");*/
	print_bits(str[3]);
	print_bits(str[2]);
	print_bits(str[1]);
	print_bits(str[0]);
	return (0);
}
