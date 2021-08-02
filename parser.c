#include "philo.h"

int	is_number(char *value)
{
	int	i;

	i = 0;
	if (value == NULL || !value)
	{
		printf("No value found\n");
		exit(1);
	}
	while (value[i] != '\0')
	{
		if (value[i] == '-' || value[i] == '+')
			i++;
		if (!(ft_isdigit(value[i])))
			return (1);
		i++;
	}
	return (0);
}

int	value_checker(t_all *all)
{
	if (all->args->number_of_philo == -1 || all->args->to_die == -1 ||
	all->args->times_must_to_eat == -1 ||
	all->args->to_sleep == -1 || all->args->times_must_to_eat == -1)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	return (0);
}

int	parser(char **argv, t_all *all)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_number(argv[i]))
		{
			printf("Numeric argument required\n");
			exit(1);
		}
		i++;
	}
	all->args->number_of_philo = ft_atoi(argv[1]);
	all->args->to_die = ft_atoi(argv[2]);
	all->args->to_eat = ft_atoi(argv[3]);
	all->args->to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		all->args->times_must_to_eat = ft_atoi(argv[5]);
	if (value_checker(all))
	{
		printf("Invalid arguments\n");
		exit(1);
	}
	return (0);
}