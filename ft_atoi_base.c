#include "libft.h"

int 			ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char *ft_base_llong(unsigned long long int num, int base, int round)
{
    char 	*s;
    char 	*result;
    int 	i;

	if (round == 0 && num == 0)
		return (NULL);
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
	result = ft_round_dioux(&s, round);
	return (result);
}

char *ft_base_long(unsigned long int num, int base, int round)
{
	char 	*result;
    char 	*s;
    int 	i;

	if (round == 0 && num == 0)
		return (NULL);
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
	result = ft_round_dioux(&s, round);
	return (result);
}

char 			*ft_base_char(unsigned char num, int base, int round)
{
    char 	*s;
    char 	*result;
    int 	i;

	if (round == 0 && num == 0)
		return (NULL);
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
	result = ft_round_dioux(&s, round);
	return (result);
}

char *ft_base_short(unsigned short int num, int base, int round)
{
    char 	*s;
    char 	*result;
    int 	i;

	if (round == 0 && num == 0)
		return (NULL);
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
	result = ft_round_dioux(&s, round);
	return (result);
}

char *ft_base(unsigned int num, int base, int round)
{
	char 	*s;
	char 	*result;
	int 	i;

	if (round == 0 && num == 0)
		return (NULL);
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
	result = ft_round_dioux(&s, round);
	return (result);
}