/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:06:15 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:06:19 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_philo **str, int i)
{
	while (i >= 0)
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i--;
	}
	free(str);
	str = NULL;
	return (1);
}

void	free_all(t_all *all)
{
	if (all->forks)
	{
		free(all->forks);
		all->forks = NULL;
	}
	ft_free(all->philo, all->args.number_of_philo);
	if (all->for_print)
	{
		free(all->for_print);
		all->for_print = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_all				all;

	all.beginning = get_my_time();
	if (parser(argc, argv, &all) == 1)
		return (1);
	if (pthread_start(&all) == 1)
	{
		free_all(&all);
		return (1);
	}
	free_all(&all);
	return (0);
}
