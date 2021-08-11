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

static void	init_philo(t_philo *philo, int l_fork, int r_fork, t_all *all)
{
	philo->all = all;
	philo->name = l_fork;
	philo->left_fork = l_fork;
	philo->right_fork = r_fork;
	philo->to_die = get_my_time() + (u_int64_t)philo->all->args.to_die;
	philo->to_eat = 0;
	philo->to_sleep = 0;
	philo->times_must_eat = 0;
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
