#include "push_swap.h"
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
void	ft_putstr(char *str)
{
	if (str != NULL)
	{
		write(1, str, ft_strlen(str));
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	newvar;

	newvar = n;
	if (n < 0)
	{
		newvar = -n;
		ft_putchar('-');
	}
	if (newvar <= 9)
	{
		ft_putchar(newvar + 48);
	}
	if (newvar > 9)
	{
		ft_putnbr(newvar / 10);
		ft_putchar(newvar % 10 + 48);
	}
}

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\f' || c == ' '
		|| c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long				n;
	int				signe;

	n = 0;
	i = 0;
	signe = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (str[i] >= '0' && (str[i] <= '9') && str[i] != '\0')
	{
		if (((unsigned long)n > INT32_MAX)
			|| (((unsigned long)n == INT32_MAX)
				&& ((unsigned long)n % 10) > 7))
		
			return INT32_MAX;
		n = n * 10 + (*(str + (i++)) - '0');
	}
	return ((int)n * signe);
}