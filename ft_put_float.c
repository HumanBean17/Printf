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

char 				*ft_put_float_2(t_double *tmp, int round)
{
	long double		m;
	int				i;
	int 			count;
	int 			c;
	int 			*pow;
	int 			*sum;
	int 			*ar;

	count = 45 + round;
	sum = ft_new_malloc(count);
	if (tmp->exp - 16383 < 0)
		tmp->man >>= (unsigned long)(ft_abs(tmp->exp - 16383));
	else
		tmp->man <<= (unsigned long)(ft_abs(tmp->exp - 16383));
	i = 0;
	m = 0;
	//ft_print_bits(*tmp);
	while (i < 64)
	{
		if (((tmp->man >> (unsigned long)(64 - i)) & 1u) != 0)
		{
			c = i - 1;
			m += ft_double_pow(2, -c);
			//pow = ft_five_pow(c);
			//printf("p = %d || ", c);
			//print_int(pow, i);
			//sum = ft_sum(pow, sum, count);
			//printf("sum = ");
			//print_int(sum, count);
		}
		i++;
	}
	//printf("%Lf\n", m);
	//print_int(sum, count);
	return (NULL);
}

char 			*ft_put_exp(long double num, int round)
{
	t_uprintf	*tmp;

	if (round == 0)
		round = 6;
	tmp = (t_uprintf *)malloc(sizeof(t_uprintf));
	tmp->number = num;
	return (NULL);
}

char 			*ft_put_float(long double num, int round)
{
	t_uprintf	*tmp;

	if (round == 0)
		round = 6;
	tmp = (t_uprintf *)malloc(sizeof(t_uprintf));
	tmp->number = num;
	//ft_print_bits(tmp->num);
	return (ft_strjoin(ft_itoa((long long)num), ft_put_float_2(&(tmp->num), round)));
}