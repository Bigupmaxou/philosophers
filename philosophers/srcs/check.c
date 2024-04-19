/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:48:26 by maxime            #+#    #+#             */
/*   Updated: 2024/04/19 18:41:30 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	limits(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if(nbr > INT_MAX || nbr < 0)
	{
		return(1);
	}
	return(0);
}

int	checknbr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("pas de lettres dans vos arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	checkarg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if(!imits(av[i]))
		{	
			printf("erreur du format d'argument\n");
			return(0);
		}
		i++;
	}
	return (0);
}
