/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:59:03 by maxime            #+#    #+#             */
/*   Updated: 2024/05/17 09:05:51 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
	
void	init_data(int ac, char **av, t_data *philou)
{
	int	i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		philou->nb_philo = ft_atoi(av[1]);
		philou->time_to_die = ft_atoi(av[2]);
		philou->time_to_eat = ft_atoi(av[3]);
		philou->time_to_sleep = ft_atoi(av[4]);
		philou->nb_eat_min = -1;
		if(ac == 6)
			philou->nb_eat_min = ft_atoi(av[5]);
		philou->all_ate = 0;
		philou->death = 0;
		i++;
	}
}

void	init_philo(t_data *data)
{
	int	i;
	
	i = 0;
	data->start_time = ft_timestamp();
	while(i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_eat = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].fork1 = 0;
		data->philo[i].fork2 = 0;
		data->philo[i].data = data;
		data->fork_available[i] = 1;
		i++;
	}
}
	
int	init_thread(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_philo)
	{
		pthread_mutex_init(&(data->mutex_forks[i]), NULL);
		i++;
	}
	if(pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	if(pthread_mutex_init(&(data->check_death), NULL))
		return (1);
	if(pthread_mutex_init(&(data->print), NULL))
		return (1);
	return(0);
}
