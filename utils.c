#include "philo.h"

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

void	init_philo(t_philo *philo, int name, int left_fork, int right_fork)
{
	philo->name = name;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
}

void	init_philosophers(t_philo **philo, int forks)
{
	int			i;

	i = 0;
	while (i < forks)
	{
		if (i == forks - 1)
			init_philo(philo[i], i, i, 0);
		else
			init_philo(philo[i], i, i, i + 1);
		i++;
	}
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
