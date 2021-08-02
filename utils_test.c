#include "philo.h"

//pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;

void init_philosopher(t_philospher *philosopher, const char *name, unsigned left_fork, unsigned right_fork)
{
	philosopher->name = name;
	philosopher->left_fork = left_fork;
	philosopher->right_fork = right_fork;
}

void init_table(t_table *table)
{
	size_t		i;
	for (i = 0; i < PHT_SIZE; i++) {
		pthread_mutex_init(&table->forks[i], NULL);
	}
}