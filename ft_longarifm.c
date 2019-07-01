#include "libft.h"

char 		*ft_round(int *a, int round, unsigned long first)
{
	char 	*s;
	char 	*c;
	char 	*res;
	int 	i;
	int 	len;

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
	mlt[0] = n;
	ft_move(&mlt);
	mlt[0] = n - 1;
	return (mlt);
}