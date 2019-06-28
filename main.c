#include "libft.h"

int main()
{
	double 		d = 2.43323;
	long double sum = 0;
	int 		count = 0;

	/*
	print_int(ft_five_pow(7), ft_five_pow(7)[0]);
	print_int(ft_five_pow(54), ft_five_pow(54)[0]);
	print_int(ft_sum(ft_five_pow(54), ft_five_pow(7)), ft_five_pow(54)[0]);
	*/
	print_int(ft_five_pow(2), ft_five_pow(2)[0]);
	printf("%.50f\n", d);
	ft_printf("%.50f\n", d);
	return 0;
}