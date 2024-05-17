/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:39:33 by maxime            #+#    #+#             */
/*   Updated: 2024/05/17 09:50:17 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if(ac < 5 || ac > 6)
		printf("erreur du nombre d 'arguments\n");
	else if (checkarg(av))
		printf("Erreur de format d arguiments \n");
	else
	{
		 printf("bravo tout vos arguments ont le bon format\n");
		init_data(ac, av, &data);
		init_philo(&data);
		init_thread(&data);
		ft_create_threads(&data);
	}
	return(0);
}
