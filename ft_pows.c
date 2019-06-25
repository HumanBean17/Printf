#include "libft.h"

int 			*ft_five_pow(int n)
{
	int 	i;
	int 	*b;
	int 	*result;

	i = 1;
	result = ft_new_malloc(n + 1);
	b = ft_new_malloc(n + 1);
	result[n - 1] = 5;
	b[n - 1] = 5;
	while (i < n)
	{
		result = ft_mlt(result, b, n);
		i++;
	}
	return (result);
}

long double 	ft_double_pow(long double num, int pow)
{
	int 				flag;
	long double 		mult;

	flag = 0;
	mult = 1;
	if (pow < 0)
	{
		pow *= -1;
		flag = 1;
	}
	while (pow > 0)
	{
		pow--;
		mult *= num;
	}
	if (flag == 1)
		return (1.0 / mult);
	return (mult);
}