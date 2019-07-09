#include "libft.h"

void			ft_print_bits(t_double tmp)
{
	printf("========\nSIGN : %s\n", ft_base(tmp.sign, 2, 0));
	printf("EXP : %s (%u)\n", ft_base(tmp.exp, 2, 0), tmp.exp);
	printf("MAN : %s (%lu)\n========\n", ft_base(tmp.man, 2, 0), tmp.man);
}

void            print_check(int *a, int size)
{
    int i;
    printf("(%d)", a[0]);
    for (i = 1; a[i] == 0 && i < size; i++);
    for (int j = i; j < size; j++)
        printf("%d", a[j]);
    printf("\n");
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

int             *ft_dec_initil(t_double *tmp)
{
	if (tmp->exp - 16383 < 0)
		return (ft_cast_2(0, 64));
    else if ((tmp->exp - 16383) < 64)
		return (ft_cast_2(tmp->man >> (unsigned long) (63 - ft_abs(tmp->exp - 16383)), ft_abs(tmp->exp - 16383)));
    return (ft_cast_2(tmp->man , ft_abs(tmp->exp - 16383)));
}

int             *ft_fract_initil(t_double *tmp, int round)
{
    tmp->man = tmp->exp - 16383 < 0 ? tmp->man >> (unsigned long)(ft_abs(tmp->exp - 16383)) :
        tmp->man << (unsigned long)(ft_abs(tmp->exp - 16383));
    if (ft_abs(tmp->exp - 16383) >= 64)
    	tmp->man = 0;
    return (ft_cast_1(tmp->man, round));
}

char 			*ft_put_float_2(t_double *tmp, int round)
{
	int 			*frac;
	int 	        *dec;
	char 			*str_frac;
	char            *str_dec;
	char            *result;

	dec = ft_dec_initil(tmp);
	frac = ft_fract_initil(tmp, round);
	//exit(0);
	ft_round(&dec, &frac, round);
    //print_int(dec, dec[0] + 1);
    //print_int(frac, frac[0] + 1);
	str_frac = ft_convert_1(frac, round);
	str_dec = ft_convert_2(dec, tmp->sign);
	result = ft_strjoin(str_dec, str_frac);
	ft_strdel(&str_dec);
	ft_strdel(&str_frac);
	return (result);
}

char 			*ft_put_float(long double num, int round)
{
	t_uprintf	*tmp;
	char 		*str;

	tmp = (t_uprintf *)malloc(sizeof(t_uprintf));
	tmp->number = num;
	//ft_print_bits(tmp->num);
	round = round == -1 ? 6 : round;
	str = ft_put_float_2(&(tmp->num), round);
	free(tmp);
	return (str);
}