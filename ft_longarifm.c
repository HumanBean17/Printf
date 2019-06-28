#include "libft.h"

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

int 			*ft_sum(int *a, int *b, int c)
{
	int 		a_size;
	int 		i;

	i = 1;
	a_size = a[0];
	//new_b = ft_shift_right(b, a[0], b[0]);
	//print_int(new_b, a_size + 1);
	//print_int(a, a_size + 1);
	//printf("size = %d\n", a_size);
	while (i < c)
	{
		//printf("a = %d b = %d\n", a[i], new_b[i]);
		if (i > a_size)
			a[i] = 0;
		else
			a[i] += b[i];
		i++;
	}
	ft_move(&a, a_size);
	//print_int(a, 50);
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

int 			*ft_int_cpy(int *a)
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
	//printf("%d\n", len);
	printf("a = "); print_int(a, len);
	printf("b = "); print_int(b, len);
	printf("\n");
	return (b);
}

int 			*ft_mlt(int *a, int *b, int n)
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
	ft_move(&mlt, n);
	mlt[0] = n - 1;
	//print_int(mlt, n);
	return (mlt);
}