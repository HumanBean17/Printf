#include "libft.h"

char 			*ft_put_exp_2(t_double *tmp, int round)
{
	int				i;
	int 			*sum;
	int 			*pow;
	char 			*s;

	i = 0;
	sum = ft_new_malloc(90 + round);
	sum[0] = 90 + round;
	if (tmp->exp - 16383 < 0)
		tmp->man >>= (unsigned long)(ft_abs(tmp->exp - 16383));
	else
		tmp->man <<= (unsigned long)(ft_abs(tmp->exp - 16383));
	while (i < 64)
	{
		if (((tmp->man >> (unsigned long)(64 - i)) & 1u) != 0)
		{
			pow = ft_long_pow(i - 1, 0);
			ft_sum(&sum, pow);
			ft_int_del(&pow);
		}
		i++;
	}
	if (sum[round + 1] >= 5)
		sum[round]++;
	ft_move(&sum);
	s = ft_round(sum, round, 0);
	ft_int_del(&sum);
	return (s);
}

char 			*ft_put_exp(long double num, int round)
{
	t_uprintf	*tmp;
	char 		*str;

	tmp = (t_uprintf *)malloc(sizeof(t_uprintf));
	tmp->number = num;
	round = round < 0 ? 6 : round;
	if (round != 0)
	{
		str = ft_strjoin(ft_itoa((long long) num), ft_put_exp_2(&(tmp->num), round));
	}
	else
		str = ft_itoa((long long)num);
	free(tmp);
	return (str);
}