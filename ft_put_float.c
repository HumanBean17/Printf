#include "libft.h"

void			ft_print_bits(t_double tmp)
{
	printf("========\nSIGN : %1s\n", ft_base(tmp.sign, 2));
	printf("EXP : %15s (%u)\n", ft_base(tmp.exp, 2), tmp.exp);
	printf("MAN : %64s (%lu)\n========\n", ft_base(tmp.man, 2), tmp.man);
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
	for (int i = 1; i < size; i++)
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
    int     *dec;

    if (tmp->exp - 16383 < 64)
        dec = ft_cast_1(tmp->man >> (unsigned long) (63 - ft_abs(tmp->exp - 16383)), ft_abs(tmp->exp - 16383));
    else
        dec = ft_cast_1(tmp->man, ft_abs(tmp->exp - 16383));
    return (dec);
}

int             *ft_fract_initil(t_double *tmp, int round)
{
    int     *frac;

    tmp->man = tmp->exp < 0 ? tmp->man >> (unsigned long)(ft_abs(tmp->exp - 16383)) :
        tmp->man << (unsigned long)(ft_abs(tmp->exp - 16383));
    tmp->man = tmp->exp - 16383 > 64 ? 0 : tmp->man;
    frac = ft_cast_2(tmp->man, round);
    return (frac);
}

char 			*ft_put_float_2(t_double *tmp, int round)
{
	int 			*frac;
	int 	        *dec;
	char 			*s;

	dec = ft_dec_initil(tmp);
	frac = ft_fract_initil(tmp, round);
	print_int(dec, dec[0] + 1);
	print_int(frac, frac[0] + 1);
	//s = ft_round(sum, round, r);
	return (NULL);
	return (s);
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