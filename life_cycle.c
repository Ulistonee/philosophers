#include "philo.h"

int	inspector(u_int64_t philo_now, int philo_name, t_all *all)
{
	int			n;

	n = 0;
	if (get_my_time() > philo_now)
	{
//		all->is_dead = 1;
//		printf("philo %d died\n", philo_name);
		update_time_and_print(philo_name, " died\n", all);
		pthread_mutex_lock(all->for_print);
		while (n < all->args.forks)
		{
			pthread_mutex_unlock(&all->forks[n]);
			n++;
		}
//		printf("check_exit\n");
		return (1);
	}
	return (0);
}

int	lock_the_fork(pthread_mutex_t *fork, int is_dead)
{
	if (is_dead == 0 && pthread_mutex_lock(fork) != 0)
		return (1);
	return (0);
}

void*	life_cycle(void *args)
{
	t_philo 		*philo;

	philo = (t_philo *)args;
	if (philo->name % 2 == 0)
		usleep(100);
	while (philo->all->is_dead == 0)
	{
		lock_the_fork(&philo->all->forks[philo->left_fork], philo->all->is_dead);
		update_time_and_print(philo->name, " has taken a fork\n", philo->all);
		lock_the_fork(&philo->all->forks[philo->right_fork], philo->all->is_dead);
		update_time_and_print(philo->name, " has taken a fork\n", philo->all);
		update_time_and_print(philo->name, " is eating\n", philo->all);
		my_sleep_in_ms(philo->all->args.to_eat);
		pthread_mutex_unlock(&philo->all->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->all->forks[philo->right_fork]);
		philo->to_die = get_my_time() + (u_int64_t)philo->all->args.to_die;
		update_time_and_print(philo->name, " is sleeping\n", philo->all);
		my_sleep_in_ms(philo->all->args.to_sleep);
		update_time_and_print(philo->name, " is thinking\n", philo->all);
	}
//	printf(" %d was exited\n", philo->name);
}

int	pthread_start(t_all *all)
{
	int			i;
	void		*res;

	i = 0;
	while (i < all->args.number_of_philo)
	{
//		if (i % 2 == 0)
//			usleep(100);
		if (pthread_create(&all->philo[i]->thread, NULL, life_cycle, (void *)(all->philo[i])) != 0)
			return (1);
		i++;
	}
	all->is_dead = 0;
	while (all->is_dead == 0)
	{
		i = 0;
		while (i < all->args.number_of_philo)
		{
//			usleep(100);
			if (inspector(all->philo[i]->to_die, all->philo[i]->name, all) == 1)
			{
//				break;
				all->is_dead = 1;
			}
			i++;
		}
//		printf("check_inspector\n");
	}
	i = 0;
//	printf("check_1\n");
	while (i < all->args.number_of_philo)
	{
		pthread_join(all->philo[i]->thread, &res);
		i++;
//		printf("check_2\n");
	}
	return (0);
}