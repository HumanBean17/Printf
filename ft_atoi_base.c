#include "libft.h"

unsigned long 	ft_rev_num(unsigned long int num)
{
	unsigned long int x;

	x = 0;
	while (num > 0)
	{
		x = x * 10 + num % 10;
		num /= 10;
	}
	return (x);
}

int 			ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char 			*ft_base_llong(unsigned long long int num, int base)
{
    char 	*s;
    int 	i;

    i = 0;
    s = ft_strnew(64);
    if (num == 0)
        s[0] = '0';
    while (num > 0)
    {
        s[i] = (char)(num % base);
        if (s[i] >= 10 && s[i] <= 15)
            s[i] += 87;
        else
            s[i] += 48;
        num /= base;
        i++;
    }
    return (ft_strrev(s));
}

char 			*ft_base_long(unsigned long int num, int base)
{
    char 	*s;
    int 	i;

    i = 0;
    s = ft_strnew(64);
    if (num == 0)
        s[0] = '0';
    while (num > 0)
    {
        s[i] = (char)(num % base);
        if (s[i] >= 10 && s[i] <= 15)
            s[i] += 87;
        else
            s[i] += 48;
        num /= base;
        i++;
    }
    return (ft_strrev(s));
}

char 			*ft_base_char(unsigned char num, int base)
{
    char 	*s;
    int 	i;

    i = 0;
    s = ft_strnew(64);
    if (num == 0)
        s[0] = '0';
    while (num > 0)
    {
        s[i] = (char)(num % base);
        if (s[i] >= 10 && s[i] <= 15)
            s[i] += 87;
        else
            s[i] += 48;
        num /= base;
        i++;
    }
    return (ft_strrev(s));
}

char 			*ft_base_short(unsigned short int num, int base)
{
    char 	*s;
    int 	i;

    i = 0;
    s = ft_strnew(64);
    if (num == 0)
        s[0] = '0';
    while (num > 0)
    {
        s[i] = (char)(num % base);
        if (s[i] >= 10 && s[i] <= 15)
            s[i] += 87;
        else
            s[i] += 48;
        num /= base;
        i++;
    }
    return (ft_strrev(s));
}

char 			*ft_base(unsigned int num, int base)
{
	char 	*s;
	int 	i;

	i = 0;
	s = ft_strnew(64);
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		s[i] = (char)(num % base);
		if (s[i] >= 10 && s[i] <= 15)
			s[i] += 87;
		else
			s[i] += 48;
		num /= base;
		i++;
	}
	return (ft_strrev(s));
}