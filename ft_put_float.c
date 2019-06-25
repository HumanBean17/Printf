#include "libft.h"

void			ft_print_bits(t_double tmp)
{
	printf("========\nSIGN : %1s\n", ft_base(tmp.sign, 2));
	printf("EXP : %15s\n", ft_base(tmp.exp, 2));
	printf("MAN : %64s\n========\n", ft_base(tmp.man, 2));
}

void			print_int(int *a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d, ", a[i]);
	printf("\n");
}

char 				*ft_put_float_2(t_double *tmp, int round)
{
	int 			*a;
	int 			*b;
	unsigned long 	c;
	int				i;
	int 			count;

	a = (int *)ft_memalloc(round);
	tmp->man = (tmp->man) >> (unsigned long)(tmp->exp - 16382);
	i = 1;
	count = 0;
	ft_print_bits(*tmp);
	a = ft_five_pow(5);
	b = ft_five_pow(4);
	print_int(a, 5);
	print_int(b, 4);
	print_int(ft_sum(a, b, 5), 5);
	/*while (i < 63)
	{
		if ((tmp->man >> (unsigned long)(63 - i)) != 0)
			ft_five_pow(i);
		count++;
		i++;
	}
	//print_int(base, round);
	//return (ft_zeroes(sum, round));*/
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