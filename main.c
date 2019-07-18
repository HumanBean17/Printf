#include "libft.h"

int main()
{
	double d = -398421.000000001382139273892173827382138129429;
	long int k = 0x7325324342341;
	int s = 1678932;
	int i = 1;

	//printf(": original %d\n", printf("%05.d %#o %0#.x", 42, 42, 42));
	//printf(": mine     %d\n", ft_printf("%05.d %#o %0#.x", 42, 42, 42));

	//printf("%lf\n", 1.42l);
	//printf("%2x\n", 542);
	//printf("%.4o\n", 424242);
	printf("%.100f\n", d);
	ft_printf("%.100f\n", d);
	//ft_printf("%.4s", "42 is the answer");
	return 0;
}