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