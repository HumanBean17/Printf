#include "libft.h"

char 			*ft_round(const int *a, int round)
{
	char 	*s;
	int 	i;

	i = 1;
	s = ft_strnew(round + 1);
	s[0] = '.';
	while (i <= round)
	{
		s[i] = (char)(a[i] + 48);
		i++;
	}
	return (s);
}

int 			*ft_shift_right(int *b, int a_size, int b_size)
{
	int *new_b;

	new_b = ft_new_malloc(a_size);
	while (b_size > 0)
	{
		new_b[a_size] = b[b_size];
		//printf("new %d old %d\n", new_b[a_size], b[b_size]);
		a_size--;
		b_size--;
	}
	return(new_b);
}

void 				ft_sum(int **sum, const int *b)
{
	int 		size;
	int 		i;

	i = 1;
	size = b[0];
	//printf("%d\n", a_size);
	//new_b = ft_shift_right(b, a[0], b[0]);
	/*print_int(b, size + 1);
	print_int(*sum, (*sum)[0] + 1);
	printf("size = %d\n", size);*/
	while (i <= size)
	{
		//printf("a = %d b = %d\n", a[i], new_b[i]);
		(*sum)[i] += b[i];
		i++;
	}
	ft_move(sum);
	//ft_int_del(b);
	//print_int(a, 50);
}

void ft_move(int **a)
{
	int size;
	int i;
	int c;

	size = (*a)[0];
	//printf("%d\n", size);
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
		//printf("in del ");
		//print_int(*a, (*a)[0] + 1);
		free(*a);
		*a = NULL;
	}
}

int 			*ft_int_cpy_2(int *a, const int *b)
{
	int i;
	int len;

	len = b[0];
	i = 1;
	while (i <= len)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
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
	//print_int(a, n); print_int(b, n);
	//printf("===\n");
	while (i < n)
	{
		k = i;
		while (k < n)
		{
			mlt[i] += a[i] * b[k];
			//printf("a[i] = %d | b[k] = %d | mlt[i] = %d\n", a[i], b[k], mlt[i]);
			k++;
		}
		i++;
	}
	mlt[0] = n;
	ft_move(&mlt);
	mlt[0] = n - 1;
	//print_int(mlt, n);
	return (mlt);
}