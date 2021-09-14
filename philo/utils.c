/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:06:46 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:06:49 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = (unsigned int)(n * (-1));
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	print_message(u_int64_t time, int philo_name, char *str, t_all *all)
{
	if (all->is_dead != 1)
	{
		ft_putnbr_fd((int)time, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo_name + 1, 1);
		ft_putstr_fd(str, 1);
	}
}

void	update_time_and_print(int philo_name, char *str, t_all *all)
{
	u_int64_t		now;
	u_int64_t		timestamp;

	if (all->is_dead == 1)
		return ;
	pthread_mutex_lock(all->for_print);
	now = get_my_time();
	timestamp = now - all->beginning;
	print_message(timestamp, philo_name, str, all);
	pthread_mutex_unlock(all->for_print);
}
