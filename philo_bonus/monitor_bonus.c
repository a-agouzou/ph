/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:49:05 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 23:33:44 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

void	terminate_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		kill(data->philo[i].pid, SIGINT);
		i++;
	}
}

void	wait_for_all(t_data *data, pid_t pid)
{
	int	i;

	i = 0;
	sem_post(data->finish);
	while (i < data->nbr_of_philo)
	{
		if (data->philo[i].pid != pid)
			waitpid(data->philo[i].pid, NULL, 0);
		i++;
	}
}
