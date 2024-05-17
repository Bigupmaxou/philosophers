/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:54:36 by maxime            #+#    #+#             */
/*   Updated: 2024/05/17 08:58:27 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	signe;
	int	res;
	int	i;

	res = 0;
	signe = 1;
	i = 0;

	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if(str[i] == '-')
		signe = -1;
	while (str[i] == '_' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (res * signe);
}

long long	ft_timestamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print_action(t_data *data, int id, char *str, char *color)
{
	long long	time;

	time = ft_timestamp() - data->start_time;
	pthread_mutex_lock(&(data->print));
	if (!ft_is_dead(data))
		printf("%s %lli %i %s\n", color, time, id, str);
	pthread_mutex_unlock(&(data->print));
}

void	ft_sleep(int time)
{
	long long	start;

	start = ft_timestamp();
	while (1)
	{
		if (ft_timestamp() - start >= time)
			break ;
		usleep(50);
	}
}

int	ft_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->check_death);
	if (data->death == 1)
	{
		pthread_mutex_unlock(&(data->check_death));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(data->check_death));
		return (0);
	}
}
