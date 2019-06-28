#include "libft.h"

int 			*ft_five_pow(int n)
{
	int 	i;
	int 	*b;
	int 	*result;
	int 	*tmp;

	i = 1;
	b = ft_new_malloc(n + 1);
	b[n] = 5;
	result = ft_new_malloc(n + 1);
	result[n] = 5;
	result[0] = n;
	while (i < n)
	{
		tmp = ft_int_cpy(result);
		ft_int_del(&result);
		result = ft_mlt(tmp, b, n + 1);
		//print_int(tmp, n + 1);
		//print_int(result, n + 1);
		ft_int_del(&tmp);
		i++;
	}
	ft_int_del(&b);
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