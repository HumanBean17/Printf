#include "libft.h"

void			ft_print_bits(t_double tmp)
{
	printf("========\nSIGN : %1s\n", ft_base(tmp.sign, 2));
	printf("EXP : %15s (%lu)\n", ft_base(tmp.exp, 2), tmp.exp);
	printf("MAN : %64s (%lu)\n========\n", ft_base(tmp.man, 2), tmp.man);
}

void			print_int(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			printf("(%d)", a[i]);
		else
			printf("%d", a[i]);
	}
	printf("\n");
}

char 			*ft_put_float_2(t_double *tmp, int round)
{
	int				i;
	int 			*sum;
	int 			*pow;
	unsigned long 	r;
	char 			*s;

	i = 0;
	sum = ft_new_malloc(91 + round);
	sum[0] = 91 + round;
	r = tmp->man >> (unsigned long)(63 - ft_abs(tmp->exp - 16383));
	if (tmp->exp - 16383 < 0)
		tmp->man >>= (unsigned long)(ft_abs(tmp->exp - 16383));
	else
		tmp->man <<= (unsigned long)(ft_abs(tmp->exp - 16383));
	while (i < 64)
	{
		if (((tmp->man >> (unsigned long)(64 - i)) & 1u) != 0)
		{
			pow = ft_five_pow(i - 1);
			ft_sum(&sum, pow);
			ft_int_del(&pow);
		}
		i++;
	}
	s = ft_round(sum, round, r);
	return (s);
}

char 			*ft_put_float(long double num, int round)
{
	t_uprintf	*tmp;
	char 		*str;

	tmp = (t_uprintf *)malloc(sizeof(t_uprintf));
	tmp->number = num;
	round = round == -1 ? 6 : round;
	str = ft_put_float_2(&(tmp->num), round);
	free(tmp);
	return (str);
}