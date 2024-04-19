/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:54:36 by maxime            #+#    #+#             */
/*   Updated: 2024/04/19 17:33:07 by maxime           ###   ########.fr       */
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

