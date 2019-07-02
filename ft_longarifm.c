#include "libft.h"

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

int             *ft_cast_2(unsigned long num, int round)
{
    int *pow;
    int *frac;
    int i;

    i = 0;
    frac = ft_new_malloc(91 + round);
    frac[0] = 91 + round;
    while (i < 64 && num > 0)
    {
        if (((num >> (unsigned long)(64 - i)) & 1u) != 0)
        {
            pow = ft_long_pow(i - 1, 5);
            ft_sum(&frac, pow);
            ft_int_del(&pow);
        }
        i++;
    }
    return (frac);
}

int            *ft_cast_1(unsigned long num, int len)
{
    int *sum;
    int *pow;
    int shift;
    int i;

    i = 0;
    shift = len - 63 < 0 ? 0 : len - 63;
    len = len > 63 ? 63 : len;
    sum = ft_new_malloc(len + 1);
    sum[0] = len;
    while (len >= 0)
    {
        if (((num >> (unsigned long)i) & 1u) != 0)
        {
            pow = ft_long_pow(i + shift, 2);
            pow = ft_shift_right(&pow);
            ft_sum_2(&sum, pow);
            ft_int_del(&pow);
        }
        len--;
        i++;
    }
    return (sum);
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
    ft_move(sum);
}

void 				ft_sum(int **sum, const int *b)
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
    ft_move(sum);
}

void 				ft_move(int **a)
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
	ft_move(&mlt);
	return (mlt);
}

char 		*ft_round(int *a, int round, unsigned long first)
{
    char 	*s;
    char 	*c;
    char 	*res;
    int 	i;

    if (round == 0 && a[1] >= 5)
        first++;
    else if (a[round + 1] >= 5)
        a[round]++;
    ft_move(&a);
    c = ft_itoa(first);
    i = 1;
    s = ft_strnew(round + 2);
    while (i <= round)
    {
        if (i == 1)
            s[0] = '.';
        s[i] = (char)(a[i] + 48);
        i++;
    }
    res = ft_strjoin(c, s);
    ft_strdel(&c);
    ft_strdel(&s);
    return (res);
}