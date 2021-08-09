#include "philo.h"

void	print_philos(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->args.number_of_philo)
	{
		printf("name: %d | left_fork: %d | right_fork: %d |\n", all->philo[i]->name, all->philo[i]->left_fork, all->philo[i]->right_fork);
		i++;
	}
}

void	print_values(t_all *all)
{
	printf("number of philo - %d\n", all->args.number_of_philo);
	printf("time to die - %d\n", all->args.to_die);
	printf("time to eat - %d\n", all->args.to_eat);
	printf("time to sleep - %d\n", all->args.to_sleep);
	if (all->args.times_must_eat)
		printf("times must to eat - %d\n", all->args.times_must_eat);
}

int	main(int argc, char **argv)
{
	t_all				all;

	all.beginning = get_my_time();
	if (parser(argc, argv, &all) == 1)
		return (1);
//	print_values(&all);
//	print_philos(&all);
	if (pthread_start(&all) == 1)
	{
		//kill processes
		//free
		return (1);
	}
	return (0);
}