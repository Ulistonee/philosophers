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

void	life(t_all *all, t_philo *philo)
{
	t_philo			*philo;
	int				first_fork;
	int				second_fork;
	int 			i;
	u_int64_t		timestamp;
	u_int64_t		now;

	while (1)
	{
		sem_wait(all->forks);
		now = get_my_time();
		timestamp = now - all->beginning;
		print_message(timestamp, philo->name, "has taken a fork\n", all);
		sem_wait(all->forks);
		now = get_my_time();
		timestamp = now - all->beginning;
		print_message(timestamp, philo->name, "has taken a fork\n", all);

		sem_post(all->forks);
		}
	}
}

int	multiprocess(pid_t pid, t_philo *philo, t_all *all)
{
	int 	j;
	int 	status;

	j = 0;
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		life(all, philo);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

int	process_start(t_all *all)
{
	int			i;
	int			j;
	pid_t		*pid;

	pid = (pid_t *) malloc(sizeof (pid_t) * all->args.n_of_ph);
	if (!pid)
		return (1);
	i = 0;
	j = 0;
	while (i < all->args.n_of_ph && j < all->args.n_of_ph)
	{
		multiprocess(pid[j], (*all->ph)[i], all);
		j++;
		i++;
	}
	return (0);
}