#include "libft.h"

int main()
{
	double 		    d = -312213923829372873821232131.19429;
	int             *ar;

	ar = (int *)malloc(sizeof(int) * 10);

	printf("%p   %f\n", ar, d);
	//printf("%f\n", d);
    ft_printf("%p   %f\n", ar, d);
	return 0;
}