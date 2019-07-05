#include "libft.h"

int main()
{
	double 		    d = -31.000000001382139273892173827382138129429;
	int             *ar;
	long int             k = 0x7325324342341;

	ar = (int *)malloc(sizeof(int) * 10);

	printf("%lX\n", k);
	//printf("%f\n", d);
    ft_printf("%lX\n", k);
	return 0;
}