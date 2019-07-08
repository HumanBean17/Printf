#include "libft.h"

int main()
{
	double d = -31.000000001382139273892173827382138129429;
	long int k = 0x7325324342341;
	int s = 1678932;
	int i = 1;

	printf(": original %d\n", printf("%#o", 42));
	printf(": mine     %d\n", ft_printf("%#o", 42));
	printf("\n");
	printf(": original %d\n", printf("%#.5o", 1));
	printf(": mine     %d\n", ft_printf("%#.5o", 1));
	return 0;
}