#include "libft.h"

char                *ft_convert_1(int *a, int round)
{
    char    *s;
    int     i;
    int     j;
    int     len;


    s = ft_strnew(round + 1);
    j = 1;
    s[0] = '.';
    i = 1;
    len = a[0];
    while (i < len && i <= round)
    {
        s[j] = (char)(a[i] + 48);
        i++;
        j++;
    }
    ft_int_del(&a);
    return (s);
}

char                *ft_convert_2(int *a, int sign)
{
    char    *s;
    int     i;
    int     j;
    int     len;

    s = ft_strnew(a[0] + sign);
    j = sign == 0 ? 0 : 1;
    s[0] = j == 1 ? '-' : (char)(a[1] + 48);
    i = ft_find_start(a);
    len = a[0] + 1;
    while (i < len)
    {
        s[j] = (char)(a[i] + 48);
        i++;
        j++;
    }
    ft_int_del(&a);
    return (s);
}

int                 *ft_shift_right(int **a)
{
    int i;
    int j;
    int len;
    int *b;

    i = 1;
    j = 1;
    len = (*a)[0] + 1;
    while ((*a)[i] == 0 && i < len)
        i++;
    if (i == 1)
        return (*a);
    b = ft_new_malloc((sizeof(int) * (len - i)));
    b[0] = len - i;
    while (i < len)
    {
        b[j] = (*a)[i];
        i++;
        j++;
    }
    ft_int_del(a);
    return (b);
}

int             *ft_cast_1(unsigned long num, int round)
{
    int *pow;
    int *frac;
    int i;

    i = 0;
    frac = ft_new_malloc(64 + round);
    frac[0] = 64 + round;
    while (i < 64 && num > 0)
    {
        if (((num >> (unsigned long)(64 - i)) & 1u) != 0)
        {
        	if (i - 1 > 0)
        	{
				pow = ft_long_pow(i - 1, 5);
				ft_sum_1(&frac, pow);
				ft_int_del(&pow);
			}
        }
        i++;
    }
    return (frac);
}

int            *ft_cast_2(unsigned long num, int len)
{
    int *pow;
    int *dec;
    int shift;
    int i;

    i = 0;
    shift = len - 63 < 0 ? 0 : len - 63;
    dec = ft_new_malloc(len + 2);
    dec[0] = len == 0 ? 1 : len;
    len = len > 63 ? 63 : len;
    while (len >= 0)
    {
        if (((num >> (unsigned long)i) & 1u) != 0)
        {
            pow = ft_long_pow(i + shift, 2);
            pow = ft_shift_right(&pow);
            ft_sum_2(&dec, pow);
            ft_int_del(&pow);
        }
        len--;
        i++;
    }
    return (dec);
}

int                 ft_find_start(const int *a)
{
    int i;
    int len;

    i = 1;
    len = a[0];
    while (i < len && a[i] == 0)
        i++;
    return (i);
}

void 				ft_sum_2(int **sum, const int *b)
{
    int 		size;
    int 		i;
    int         start;

    size = b[0];
    i = size;
    start = (*sum)[0];
    while (i >= 1)
    {
        (*sum)[start] += b[i];
        start--;
        i--;
    }
    ft_move_2(sum);
}

void 				ft_sum_1(int **sum, const int *b)
{
    int 		size;
    int 		i;

    i = 1;
    size = b[0];
    while (i <= size)
    {
        (*sum)[i] += b[i];
        i++;
    }
    ft_move_1(sum);
}

void 				ft_move_1(int **a)
{
    int size;
    int i;
    int c;

    size = (*a)[0];
    i = 1;
    while (i < size)
    {
        if ((*a)[i] >= 10 && i != 1)
        {
            c = (*a)[i] / 10;
            (*a)[i - 1] += c;
            (*a)[i] %= 10;
            i = 1;
        }
        i++;
    }
}

void 				ft_move_2(int **a)
{
	int size;
	int i;
	int c;

	size = (*a)[0] + 1;
	i = 1;
	while (i < size)
	{
		if ((*a)[i] >= 10 && i != 1)
		{
			c = (*a)[i] / 10;
			(*a)[i - 1] += c;
			(*a)[i] %= 10;
			i = 1;
		}
		i++;
	}
}

void 			ft_int_del(int **a)
{
	if (a)
	{
		free(*a);
		*a = NULL;
	}
}

int 			*ft_int_cpy(const int *a)
{
	int 	len;
	int 	*b;
	int 	i;

	i = 1;
	len = a[0] + 1;
	b = ft_new_malloc(len);
	b[0] = a[0];
	while (i < len)
	{
		b[i] = a[i];
		i++;
	}
	return (b);
}

int 			*ft_mlt(const int *a, const int *b, int n)
{
	int *mlt;
	int i;
	int k;

	i = 1;
	mlt = ft_new_malloc(n);
	while (i < n)
	{
		k = i;
		while (k < n)
		{
			mlt[i] += a[i] * b[k];
			k++;
		}
		i++;
	}
	mlt[0] = n - 1;
    ft_move_2(&mlt);
	return (mlt);
}

void            ft_round(int **a, int **b, int round)
{
    if (round == 0)
    {
        if ((*b)[1] >= 5)
        {
            (*a)[(*a[0])]++;
            ft_move_2(a);
        }
        return ;
    }
    if ((*b)[round + 1] >= 5)
    {
        (*b)[round]++;
        ft_move_1(b);
    }
}