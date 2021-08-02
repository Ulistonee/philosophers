#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	int			name;
	int			left_fork;
	int			right_fork;
}				t_philo;

typedef struct s_args
{
	int			number_of_philo;
	int			forks;
	int			to_die;
	int			to_eat;
	int			to_sleep;
	int			times_must_to_eat;
}				t_args;

typedef struct s_all
{
	t_args				args;
	t_philo				**philo;
	pthread_mutex_t		*forks;

}			t_all;

int				parser(char **argv, t_all *all);
int				ft_atoi(const char *str);
int				ft_isdigit(int a);
void			init_philosophers(t_philo **philo, int forks);
int				ft_free(t_philo **str, int i);







