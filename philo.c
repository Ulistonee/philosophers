#include "philo.h"


static void	init_philo(t_philo *philo, int name, int left_fork, int right_fork, t_all *all)
{
	philo->all = all;
	philo->name = name;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
}

void	init_philosophers(t_philo **philo, int num_of_forks, t_all *all)
{
	int			i;

	i = 0;
	while (i < num_of_forks)
	{
		if (i == num_of_forks - 1)
			init_philo(philo[i], i, i, 0, all);
		else
			init_philo(philo[i], i, i, i + 1, all);
		i++;
	}
}