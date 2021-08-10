#include "philo.h"

int	main(int argc, char **argv)
{
	t_all				all;

	all.beginning = get_my_time();
	if (parser(argc, argv, &all) == 1)
		return (1);
	if (pthread_start(&all) == 1)
	{
		//kill processes
		//free
		return (1);
	}
	return (0);
}