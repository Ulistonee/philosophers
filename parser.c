#include "philo.h"

int	malloc_philo_and_mutex(t_all *all)
{
	int			i;

	if (!(all->forks = (pthread_mutex_t *) malloc(sizeof (pthread_mutex_t) * all->args.forks)))
		print_and_return("Malloc error\n", 1);
	i = 0;
	while (i < all->args.forks)
	{
		if (pthread_mutex_init(&all->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	all->philo = (t_philo **)malloc(sizeof (t_philo *) * all->args.number_of_philo + 1);
	if (!all->philo)
		print_and_return("Malloc error\n", 1);
	i = 0;
	while (i < all->args.number_of_philo)
	{
		all->philo[i] = (t_philo *) malloc(sizeof (t_philo));
		if (!all->philo[i])
			return (ft_free(all->philo, all->args.number_of_philo));
		i++;
	}
	all->philo[i] = NULL;
	return (0);
}

int	value_checker(t_all *all)
{
	if (all->args.number_of_philo == -1 || all->args.to_die == -1 ||
		all->args.times_must_eat == -1 ||
		all->args.to_sleep == -1 || all->args.times_must_eat == -1)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	return (0);
}

int	parse_args(char **argv, t_all *all)
{
	all->args.number_of_philo = ft_atoi(argv[1]);
	all->args.to_die = ft_atoi(argv[2]);
	all->args.to_eat = ft_atoi(argv[3]);
	all->args.to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		all->args.times_must_eat = ft_atoi(argv[5]);
	if (value_checker(all))
		return (1);
	all->args.forks = all->args.number_of_philo;
	if (malloc_philo_and_mutex(all) == 1)
		return (1);
	return (0);
}

void	init_args(t_all *all)
{
	all->args.number_of_philo = 0;
	all->args.forks = 0;
	all->args.to_die = 0;
	all->args.to_eat = 0;
	all->args.to_sleep = 0;
	all->args.times_must_eat = 0;
}

int	is_number(char *value)
{
	int	i;

	i = 0;
	if (value == NULL)
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

int	parser(int argc, char **argv, t_all *all)
{
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (argc == 5 || argc == 6)
	{
		init_args(all);
		i = 1;
		while (argv[i] != NULL)
		{
			if (is_number(argv[i]))
			{
				printf("Numeric argument required\n");
				return (1);
			}
			i++;
		}
		if (parse_args(argv, all) == 1)
			return (1);
		init_philosophers(all->philo, all->args.forks, all);
	}
	return (0);
}