#include "philo.h"

void	init_all(t_all *all)
{
	all->args->number_of_philo = 0;
	all->args->to_die = 0;
	all->args->to_eat = 0;
	all->args->to_sleep = 0;
	all->args->times_must_to_eat = 0;
}

void	print(t_all *all)
{
	printf("number of philo - %d\n", all->args->number_of_philo);
	printf("time to die - %d\n", all->args->to_die);
	printf("time to eat - %d\n", all->args->to_eat);
	printf("time to sleep - %d\n", all->args->to_sleep);
	if (all->args->times_must_to_eat)
		printf("times must to eat - %d\n", all->args->times_must_to_eat);
}

int	main(int argc, char **argv)
{
	t_all		all;

	if (argc < 4)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (argc == 5 || argc == 6)
	{
		init_all(&all);
		parser(argv, &all);
	}
	print(&all);
	return (0);
}