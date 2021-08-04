#include "philo.h"

void*	life_cycle(void *args)
{
	t_philo 		*philo;
	int				i;

//	printf("check\n");
	philo = (t_philo *)args;

	if (philo->name % 2 == 0)
	{
		usleep(1000);
	}
	printf("филооф #%d\n", philo->name);
	i = pthread_mutex_lock(&philo->all->forks[philo->left_fork]);
	printf("status - %d\n", i);
	printf("philo %d has taken %p fork\n", philo->name, &philo->all->forks[philo->left_fork]);
	i = pthread_mutex_lock(&philo->all->forks[philo->right_fork]);
	printf("status - %d\n", i);
	printf("philo %d has taken %p fork\n", philo->name, &philo->all->forks[philo->right_fork]);
//	printf("philo %d is eating %p %p forks\n", philo->name, &philo->all->forks[philo->left_fork], &philo->all->forks[philo->right_fork]);
	printf("philo %d is eating %d %d forks\n", philo->name, philo->left_fork, philo->right_fork);
	usleep(philo->all->args.to_eat * 10000);
	printf("philo %d is sleeping\n", philo->name);
	pthread_mutex_unlock(&philo->all->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->all->forks[philo->right_fork]);
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
//		printf("thread status %d\n", n);
//		usleep(700000);
		i++;
	}
	while (i < all->args.number_of_philo)
	{
		pthread_join()
		n = pthread_create(&all->philo[i]->thread, NULL, life_cycle, (void *)(all->philo[i]));
//		printf("thread status %d\n", n);
//		usleep(700000);
		i++;
	}
}