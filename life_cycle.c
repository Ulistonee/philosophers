/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:07:01 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:07:03 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f_fed(t_all *all)
{
	int			n;

	all->fed_up = 0;
	n = 0;
	if (all->args.times_must_eat == -2)
		return (0);
	while (n < all->args.n_of_ph)
	{
		if (all->ph[n]->to_eat >= all->args.times_must_eat)
			all->fed_up++;
		n++;
	}
	if (all->fed_up == all->args.n_of_ph)
	{
		all->fed_up = 1;
		return (1);
	}
	return (0);
}

int	inspector(u_int64_t philo_now, int philo_name, t_all *all)
{
	int			n;

	n = 0;
	if (get_my_time() > philo_now || f_fed(all) == 1)
	{
		update_time_and_print(philo_name, " died\n", all);
		pthread_mutex_lock(all->for_print);
		while (n < all->args.f)
		{
			pthread_mutex_unlock(&all->f[n]);
			n++;
		}
		usleep(500);
		pthread_mutex_unlock(all->for_print);
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

void	*life(void *args)
{
	t_philo			*philo;
	int				first_fork;
	int				second_fork;

	philo = (t_philo *)args;
	if (philo->name % 2 == 0)
	{
		usleep(100);
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	while (philo->all->is_dead == 0)
	{
		eating(philo, first_fork, second_fork);
		update_time_and_print(philo->name, " is sleeping\n", philo->all);
		my_sleep_in_ms(philo->all->args.to_sleep);
		update_time_and_print(philo->name, " is thinking\n", philo->all);
	}
	return (NULL);
}

int	pthread_start(t_all *all)
{
	int			i;

	i = 0;
	while (i < all->args.n_of_ph)
	{
		if (pthread_create(&all->ph[i]->tr, NULL, life, (all->ph[i])) != 0)
			return (1);
		i++;
	}
	while (all->is_dead == 0)
	{
		i = 0;
		while (i < all->args.n_of_ph)
		{
			if (inspector(all->ph[i]->to_die, all->ph[i]->name, all) == 1)
			{
				all->is_dead = 1;
				break ;
			}
			i++;
		}
	}
	if (wait_for_pthread(all->args.n_of_ph, *all->ph) == 1)
		return (1);
	return (0);
}
