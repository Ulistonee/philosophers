/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:23:39 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:23:44 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep_in_ms(int waiting)
{
	u_int64_t		now;

	now = get_my_time();
	while (get_my_time() < now + waiting)
		usleep(100);
}

u_int64_t	get_my_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	print_and_return(char *str, int ret)
{
	printf("%s\n", str);
	return (ret);
}

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		positive;

	i = 0;
	result = 0;
	positive = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		positive = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (((result > 2147483647) && positive)
			|| ((result > 2147483648) && !positive))
			return (-1);
		i++;
	}
	if (positive == 0)
		result = result * (-1);
	return ((int)result);
}
