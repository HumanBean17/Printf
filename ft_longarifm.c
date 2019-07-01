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
    //printf("a = ");
    //print_int((*a), len);
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

int            *ft_cast_1(unsigned long num, int len)
{
    int *sum;
    int *pow;
    int const_len;
    int i;

    const_len = len;
    i = 0;
    sum = ft_new_malloc(len + 1);
    sum[0] = len;
    printf("%d\n", len);
    //printf("base = %s\n", ft_base(num, 2));
    while (len >= 0)
    {
        if (((num >> (unsigned long)i) & 1u) != 0)
        {
            pow = ft_long_pow(i, 2);
            pow = ft_shift_right(&pow);
            ft_sum_2(&sum, pow);

            printf("1");
            /*printf("pow = %d\n", i);
            printf("sum = ");
            print_int(sum, sum[0] + 1);
            printf("pow = ");
            print_int(pow, pow[0] + 1);*/

            ft_int_del(&pow);
        }
        printf("0");
        /*else if (const_len > 63)
        {
            pow = ft_long_pow(i, 2);
            pow = ft_shift_right(&pow);
            ft_sum_2(&sum, pow);
            ft_int_del(&pow);
        }*/
        len--;
        i++;
    }
    printf("\n");
    print_int(sum, sum[0] + 1);
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

    /*printf("sum = ");
    print_int((*sum), (*sum)[0] + 1);
    printf("b = ");
    print_int((int *)b, b[0] + 1);
    printf("start = %d\n", start);
    printf("size = %d\n", size);*/

    while (i >= 1)
    {
        //printf("%d %d\n", (*sum)[start], b[i]);
        (*sum)[start] += b[i];
        start--;
        i--;
    }
    ft_move(sum);
    /*printf("res = ");
    print_int((*sum), (*sum)[0] + 1);
    printf("\n");*/
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
	//print_int(mlt, mlt[0] + 1);
	ft_move(&mlt);
    //print_int(mlt, mlt[0] + 1);
    //printf("\n");
	//mlt[0] = n - 1;
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