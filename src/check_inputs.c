#include "../push_swap.h"

int	is_int(char *str)
{
	int		i;
	int		sign;
	long	numb;

	i = 0;
	sign = 1;
	numb = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i] - '0') * sign + (numb * 10);
		if (numb > 2147483647)
			return (0);
		if (numb < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*no_p(char *str)
{
	if (str[0] == '+')
		return (str + 1);
	return (str);
}

int	check_dup(int argc, char *argv[])
{
	int		i;
	int		j;

	j = 1;
	i = j + 1;
	while (j < argc)
	{
		while (i < argc)
		{
			if (!ft_strncmp(no_p(argv[i]), no_p(argv[j]), 11))
				return (0);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (1);
}

int	check_errors(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	if (!check_dup(argc, argv))
		return (0);
	return (1);
}
