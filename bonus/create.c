/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:57:14 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/20 00:01:52 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_philo	*create_philo(t_data	*data)
{
	t_philo	*philo;
	int i;

	i = 0;
	philo = NULL;
	while(i < data->nbr_of_philo)
	{
		philo = ft_addfront(philo,ft_create_ph(i, data));
		i++;
	}
	sem_unlink("sem_ph");
	sem_unlink("sem_print");
	data->forks = sem_open("sem_ph", O_CREAT, 0666, data->nbr_of_philo);
	data->print = sem_open("sem_print", O_CREAT, 0666, 1);
	return (philo);
}