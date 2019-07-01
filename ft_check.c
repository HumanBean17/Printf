#include "libft.h"

int 	ft_type_and(const char c)
{
	if (c != 'd' && c != 'i' && c != 'o' &&
		c != 'u' && c != 'x' && c != 'X' &&
		c != 'e' && c != 'E' && c != 'f' &&
		c != 'F' && c != 'g' && c != 'G' &&
		c != 'a' && c != 'A' && c != 'c' &&
		c != 's' && c != 'C' && c != 'S' &&
		c != 'p' && c != 'n' && c != '%')
		return (1);
	return (0);
}

int 	ft_type_or(const char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' ||
		c == 'e' || c == 'E' || c == 'f' ||
		c == 'F' || c == 'g' || c == 'G' ||
		c == 'a' || c == 'A' || c == 'c' ||
		c == 's' || c == 'C' || c == 'S' ||
		c == 'p' || c == 'n' || c == '%')
		return (1);
	return (0);
}

int 	ft_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' ||
	c == ' ' || c == '+' || c == '\'' || c == '|')
		return (1);
	return (0);
}

int 	ft_len(const char c)
{
	if (c == 'h' || c == 'l' || c == 'L' ||
	c == 'q' || c == 'j' || c == 'z' || c == 't')
		return (1);
	return (0);
}

void	ft_print_flag(t_flags *tmp)
{
	printf("FLAGS : ");
	if (!tmp)
		printf("EMPTY");
	while (tmp)
	{
		if (tmp->flag_next)
			printf("%c, ", tmp->flag);
		else
			printf("%c ", tmp->flag);
		tmp = tmp->flag_next;
	}
	printf("\n");
}

void	ft_print(t_printf *tmp)
{
	ft_print_flag(tmp->flag);
	if (tmp->width)
		printf("WIDTH : %d\n", tmp->width);
	else
		printf("WIDTH : 0\n");
	if (tmp->acc)
		printf("ACC : %d\n", tmp->acc);
	else
		printf("ACC : 0\n");
	printf("LEN : %d%d\n", tmp->len[0], tmp->len[1]);
	printf("TYPE : %c\n", tmp->type);
}