/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:06:29 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:06:31 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_for_pthread(int number_of_philos, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < number_of_philos)
	{
		if (pthread_join(philo[i].tr, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	eating(t_philo *philo, int first_fork, int second_fork)
{
	lock_the_fork(&philo->all->f[first_fork], philo->all->is_dead);
	update_time_and_print(philo->name, " has taken a first fork\n", philo->all);
	lock_the_fork(&philo->all->f[second_fork], philo->all->is_dead);
	update_time_and_print(philo->name, " has taken a second fork\n", philo->all);
	update_time_and_print(philo->name, " is eating\n", philo->all);
	philo->to_die = get_my_time() + (u_int64_t)philo->all->args.to_die;
	my_sleep_in_ms(philo->all->args.to_eat);
	pthread_mutex_unlock(&philo->all->f[first_fork]);
	pthread_mutex_unlock(&philo->all->f[second_fork]);
	philo->to_eat++;
}

static void	init_philo(t_philo *philo, int l_fork, int r_fork, t_all *all)
{
	philo->all = all;
	philo->name = l_fork;
	philo->left_fork = l_fork;
	philo->right_fork = r_fork;
	philo->to_die = get_my_time() + (u_int64_t)philo->all->args.to_die;
	philo->to_eat = 0;
}

void	init_philosophers(t_philo **philo, int num_of_forks, t_all *all)
{
	int			i;

	i = 0;
	while (i < num_of_forks)
	{
		if (i == num_of_forks - 1)
			init_philo(philo[i], i, 0, all);
		else
			init_philo(philo[i], i, i + 1, all);
		i++;
	}
}
