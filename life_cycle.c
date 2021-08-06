#include "philo.h"

void*	life_cycle(void *args)
{
	t_philo 		*philo;
	int				i;
	int				now;

	now = get_my_time();
	printf("now - %d\n", now);
	philo = (t_philo *)args;
	if (philo->name % 2 == 0)
		usleep(1000000);
	i = pthread_mutex_lock(&philo->all->forks[philo->left_fork]);
	i = pthread_mutex_lock(&philo->all->forks[philo->right_fork]);
	printf("philo %d is eating with %d %d forks\n", philo->name, philo->left_fork, philo->right_fork);
	usleep(philo->all->args.to_eat * 10000);
	pthread_mutex_unlock(&philo->all->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->all->forks[philo->right_fork]);
	printf("philo %d is sleeping\n", philo->name);
	usleep(philo->all->args.to_sleep * 10000);
	printf("philo %d is thinking\n", philo->name);
	return (NULL);
}

void	pthread_start(t_all *all)
{
	int			i;
	int			n;

	i = 0;
	while (i < all->args.number_of_philo)
	{
		n = pthread_create(&all->philo[i]->thread, NULL, life_cycle, (void *)(all->philo[i]));
//		usleep(700000);
		i++;
	}
	i = 0;
	while (i < all->args.number_of_philo)
	{
		pthread_join(all->philo[i]->thread, NULL);
		i++;
	}
}