#include "libft.h"

int main()
{
	double d = -31.000000001382139273892173827382138129429;
	long int k = 0x7325324342341;
	int s = -1678932;

//printf("%d", (char *)printf("% %", "test"));
//printf("%d", (char *)ft_printf("% %", "test"));
	printf(" : original %d\n", (int)printf("%X", 4294967296));
	printf(" : mine %d\n", (int)ft_printf("%X", 4294967296));
	return 0;
}