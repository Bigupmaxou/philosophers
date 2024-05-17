/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:36:00 by maxime            #+#    #+#             */
/*   Updated: 2024/05/17 09:12:11 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
// for write, usleep

# include <sys/time.h>
// for gettimeofday

# include <stdio.h>
// for printf

# include <pthread.h>
// for pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_lock, pthread_mutext_destroy, pthread_mutext_unlock

# include <string.h>
// for memset

# include <stdlib.h>
//for malloc, free

#include <limits.h>
// for arg limits 

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				left_fork;
	int				right_fork;
	int				fork1;
	int				fork2;
	pthread_t		thread_id;
	struct s_data	*data;
	long long		last_meal;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat_min;
	int					all_ate;
	int					death;
	char				fork_available[250];
	pthread_mutex_t		mutex_forks[250];
	pthread_mutex_t		meal_check;
	pthread_mutex_t		check_death;
	pthread_mutex_t		print;
	t_philo				philo[250];
	long long			start_time;
}	t_data;

int			ft_atoi(const char *str);
void                 	init_data(int ac, char **av, t_data *data);
void			init_philo(t_data *data);
int                     checkarg(char **av);
int                     checknbr(char *av);
int                     limitsnbr(char *av);
void    		ft_putdown_fork(t_philo *philo, t_data *data);
void    		ft_take_forks(t_philo *philo, t_data *data);
void    		ft_eat(t_philo *philo, t_data *data);
void    		*routine(void *philo_void);
int     	ft_create_threads(t_data *data);
void    	check_die(t_data *data, t_philo *philo);
void    	ft_loop_check(t_data *data, t_philo *philo);
void    	ft_exit_mutex(t_data *data);
int     	ft_create_threads(t_data *data);
void    	*routine(void *philo_void);
void    	ft_eat(t_philo *philo, t_data *data);
void    	ft_take_forks(t_philo *philo, t_data *data);
void    	ft_putdown_fork(t_philo *philo, t_data *data);
long long       ft_timestamp(void);
void    ft_print_action(t_data *data, int id, char *str, char *color);
void    ft_sleep(int time);
int     ft_is_dead(t_data *data);
int    init_thread(t_data *data);

#endif
