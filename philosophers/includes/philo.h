/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:36:00 by maxime            #+#    #+#             */
/*   Updated: 2024/04/18 17:22:57 by maxime           ###   ########.fr       */
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

typedef struct	s_philo
{
	int		numeroid;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	struct s_philo	*next;
}	t_philo;

int			ft_atoi(const char *str);
t_philo		*init_philo(int nbrphilo, int timedie, int timeat, int timesleep);
int			checkarg(char **av);
int			checknbr(char *av);
int			limitsnbr(char *av);

#endif
