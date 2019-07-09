#include "libft.h"

int main()
{
	double d = -31.000000001382139273892173827382138129429;
	long int k = 0x7325324342341;
	int s = 1678932;
	int i = 1;

	printf(": original %d\n", printf("%#040o", 39831));
	printf(": mine     %d\n", ft_printf("%#040o", 39831));

	//printf("%lf\n", 1.42l);
	//ft_printf("%lf\n", 1.42l);
	return 0;
}