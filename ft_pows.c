#include "libft.h"

int             *ft_long_pow(int power, int num)
{
	int 	i;
	int 	*b;
	int 	*result;
	int 	*tmp;

	i = 1;
	power = power < 0 ? 1 : power;
	if (power == 0 && num != 5)
    {
	    result = ft_new_malloc(2);
	    result[0] = 1;
	    result[1] = 1;
        return (result);
    }
	b = ft_new_malloc(power + 1);
	b[power] = num;
	result = ft_new_malloc(power + 1);
	result[power] = num;
	result[0] = power;
	while (i < power)
	{
		tmp = ft_int_cpy(result);
		ft_int_del(&result);
		result = ft_mlt(tmp, b, power + 1);
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