#include "libft.h"

int main()
{
	double 		    d = -232131.19429;
	int             *ar;

	ar = (int *)malloc(sizeof(int) * 10);

	printf("%p\n", ar);
	//printf("%f\n", d);
    ft_printf("%p\n", ar);
	return 0;
}