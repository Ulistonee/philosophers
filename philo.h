/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:06:35 by rchalmer          #+#    #+#             */
/*   Updated: 2021/08/11 20:06:38 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_all	t_all;

typedef struct s_philo
{
	int						name;
	t_all					*all;
	int						left_fork;
	int						right_fork;
	u_int64_t				to_die;
	int						to_eat;
	pthread_t				tr;
}				t_philo;

typedef struct s_args
{
	int						n_of_ph;
	int						f;
	int						to_die;
	int						to_eat;
	int						to_sleep;
	int						times_must_eat;
}				t_args;

typedef struct s_all
{
	t_args					args;
	t_philo					**ph;
	pthread_mutex_t			*f;
	int						is_dead;
	u_int64_t				beginning;
	pthread_mutex_t			*for_print;
	int						fed_up;

}			t_all;

int				parser(int argc, char **argv, t_all *all);
int				ft_atoi(const char *str);
int				ft_isdigit(int a);
void			init_philosophers(t_philo **philo,
					int num_of_forks, t_all *all);
int				ft_free(t_philo **str, int i);
int				print_and_return(char *str, int ret);
u_int64_t		get_my_time(void);
int				pthread_start(t_all *all);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			print_message(u_int64_t time,
					int philo_name, char *str, t_all *all);
void			update_time_and_print(int philo_name, char *str, t_all *all);
void			my_sleep_in_ms(int waiting);
void			free_all(t_all *all);
int				lock_the_fork(pthread_mutex_t *fork, int is_dead);
void			eating(t_philo *philo, int first_fork, int second_fork);
int				wait_for_pthread(int number_of_philos, t_philo *philo);
int				is_number(char *value);
#endif
