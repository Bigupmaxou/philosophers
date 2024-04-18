/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:39:33 by maxime            #+#    #+#             */
/*   Updated: 2024/04/18 17:50:36 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	if(ac < 5 || ac > 6)
	{
		printf("erreur du nombre d 'arguments");
		return (0);
	}
	if(ac == 5 || ac == 6)
	{
		if(checkarg(av))
		{
			printf("erreur du format d'arguments");
			return(0);
		}
		printf("bravo tout vos arguments ont le bon format");
	}
	return(0);
}
