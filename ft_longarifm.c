#include "libft.h"

int 			*ft_sum(int *a, int *b, int size)
{
	int j;
	int i;
	int *new_b;

	i = 0;
	j = 0;
	new_b = ft_new_malloc(size);
	while (ft_isdigit(a[i]))
		j++;
	printf("%d\n", j);
	while (j < size)
	{
		new_b[j] = b[i];
		i++;
		j++;
	}
	i = 0;
	print_int(new_b, size);
	while (i < size)
	{
		a[i] += b[i];
		i++;
	}
	print_int(a, size);
	ft_move(&a, size);
	return (a);
}

void			ft_move(int **a, int size)
{
	int i;
	int c;

	i = 1;
	while (i < size)
	{
		if ((*a)[i] >= 10)
		{
			c = (*a)[i] / 10;
			(*a)[i - 1] += c;
			(*a)[i] %= 10;
			i = 1;
		}
		i++;
	}
}

int 			*ft_mlt(int *a, int *b, int n)
{
	int *mlt;
	int i;
	int k;

	i = 0;
	mlt = ft_new_malloc(n);
	//print_int(a, n);
	//print_int(b, n);
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
	ft_move(&mlt, n);
	//print_int(mlt, n);
	return (mlt);
}