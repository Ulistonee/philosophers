#include "philo.h"

int	inspector(u_int64_t philo_now, int philo_name)
{
	if (get_my_time() > philo_now)
	{
		printf("philo %d died\n", philo_name);
		return (1);
	}
	return (0);
}

void*	life_cycle(void *args)
{
	t_philo 		*philo;


	philo = (t_philo *)args;
	philo->to_die = get_my_time() + (u_int64_t)philo->all->args.to_die;
	if (philo->name % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->all->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->all->forks[philo->right_fork]);
//		printf("philo %d is eating with %d %d forks\n", philo->name, philo->left_fork, philo->right_fork);
		ft_putstr_fd("philo", 1);
		ft_putnbr_fd(philo->name, 1);
		ft_putstr_fd("has started eating\n", 1);
		usleep(philo->all->args.to_eat * 10000);
		philo->to_die = get_my_time() + (u_int64_t)philo->all->args.to_die;
		pthread_mutex_unlock(&philo->all->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->all->forks[philo->right_fork]);
		printf("philo %d is sleeping\n", philo->name);
		usleep(philo->all->args.to_sleep * 10000);
		printf("philo %d is thinking\n", philo->name);
	}
}

int	pthread_start(t_all *all)
{
	int			i;
	void		*res;

	i = 0;
	while (i < all->args.number_of_philo)
	{
		if (pthread_create(&all->philo[i]->thread, NULL, life_cycle, (void *)(all->philo[i])) != 0)
			return (1);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < all->args.number_of_philo)
		{
			usleep(200);
			if (inspector(all->philo[i]->to_die, all->philo[i]->name) == 1)
				return (1);
			i++;
		}
	}
	i = 0;
	while (i < all->args.number_of_philo)
	{
		pthread_join(all->philo[i]->thread, &res);
		i++;
	}
	return (0);
}