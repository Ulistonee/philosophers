#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_all t_all;

typedef struct s_philo
{
	int						name;
	t_all					*all;
	int 					left_fork;
	int 					right_fork;
	u_int64_t				to_die;
	int						to_eat;
	int						to_sleep;
	int						times_must_eat;
	pthread_t				thread;
}				t_philo;

typedef struct s_threads
{
	pthread_t		*threads;
}				t_threads;

typedef struct s_args
{
	int						number_of_philo;
	int						forks;
	int						to_die;
	int						to_eat;
	int						to_sleep;
	int						times_must_eat;
}				t_args;

typedef struct s_all
{
	t_args				args;
	t_philo				**philo;
	pthread_mutex_t		*forks;

}			t_all;

int				parser(int argc, char **argv, t_all *all);
int				ft_atoi(const char *str);
int				ft_isdigit(int a);
void			init_philosophers(t_philo **philo, int num_of_forks, t_all *all);
int				ft_free(t_philo **str, int i);
int				print_and_return(char *str, int ret);
u_int64_t		get_my_time();
int				pthread_start(t_all *all);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);


#endif








