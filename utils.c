#include "philo.h"

int	get_my_time()
{
	struct timeval		tv;
	int					get_time;

	get_time = gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	print_and_return(char *str, int ret)
{
	printf("%s\n", str);
	return (ret);
}

int	ft_free(t_philo **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (1);
}

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		positive;

	i = 0;
	result = 0;
	positive = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
	(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		positive = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (((result > 2147483647) && positive) ||
		((result > 2147483648) && !positive))
			return (-1);
		i++;
	}
	if (positive == 0)
		result = result * (-1);
	return ((int)result);
}
