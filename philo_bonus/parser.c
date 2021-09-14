/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:07:10 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:07:14 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_philo(t_all *all)
{
	int			i;

	all->ph = (t_philo **)malloc(sizeof (t_philo *) * all->args.n_of_ph + 1);
	if (!all->ph)
		print_and_return("Malloc error\n", 1);
	i = 0;
	while (i < all->args.n_of_ph)
	{
		all->ph[i] = (t_philo *) malloc(sizeof (t_philo));
		if (!all->ph[i])
			return (ft_free(all->ph, all->args.n_of_ph));
		i++;
	}
	all->ph[i] = NULL;
	return (0);
}

int	value_checker(t_all *all)
{
	if (all->args.n_of_ph == -1 || all->args.to_die == -1
		|| all->args.times_must_eat == -1 || all->args.to_sleep == -1
		|| all->args.times_must_eat == -1)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	return (0);
}

int	parse_args(char **argv, t_all *all)
{
	all->args.n_of_ph = ft_atoi(argv[1]);
	all->args.to_die = ft_atoi(argv[2]);
	all->args.to_eat = ft_atoi(argv[3]);
	all->args.to_sleep = ft_atoi(argv[4]);
	all->is_dead = 0;
	all->fed_up = 0;
	if (argv[5])
		all->args.times_must_eat = ft_atoi(argv[5]);
	if (value_checker(all))
		return (1);
	all->args.f = all->args.n_of_ph;
	if (malloc_philo(all) == 1)
		return (1);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_INSPECT);
	sem_unlink(SEM_PRINT);
	all->forks = sem_open(SEM_FORK, O_CREAT, 0777, all->args.n_of_ph);
	if (all->forks == SEM_FAILED)
		return (1);
	all->inspect = sem_open(SEM_INSPECT, O_CREAT, 0777, 1);
	if (all->inspect == SEM_FAILED)
		return (1);
	all->print = sem_open(SEM_PRINT, O_CREAT, 0777, 1);
	if (all->print == SEM_FAILED)
		return (1);
	return (0);
}

void	init_args(t_all *all)
{
	all->args.n_of_ph = 0;
	all->args.f = 0;
	all->args.to_die = 0;
	all->args.to_eat = 0;
	all->args.to_sleep = 0;
	all->args.times_must_eat = -2;
}

int	parser(int argc, char **argv, t_all *all)
{
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (argc == 5 || argc == 6)
	{
		init_args(all);
		i = 1;
		while (argv[i] != NULL)
		{
			if (is_number(argv[i]))
			{
				printf("Numeric argument required\n");
				return (1);
			}
			i++;
		}
		if (parse_args(argv, all) == 1)
			return (1);
		init_philosophers(all->ph, all->args.f, all);
	}
	return (0);
}
