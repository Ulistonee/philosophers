#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#define _CRT_RAND_S
#include <stdlib.h>
#include <pthread.h>
#define PHT_SIZE 5
#define Sleep(X) usleep(X)
#define wait() scanf("5")

typedef struct s_philosopher
{
	const char						*name;
	unsigned						left_fork;
	unsigned						right_fork;
	pthread_t						thread;
}				t_philospher;

typedef struct s_threads
{
	pthread_t						*threads;
}				t_threads;

typedef struct s_table
{
	pthread_mutex_t					forks[PHT_SIZE];
}				t_table;

typedef struct s_philosopher_args
{
	const t_philospher				*philosopher;
	const t_table					*table;
}				t_philosopher_args;

void			init_philosopher(t_philospher *philosopher, const char *name, unsigned left_fork, unsigned right_fork);
void			init_table(t_table *table);
int				parser(char **argv);





