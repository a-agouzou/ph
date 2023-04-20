/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:33:23 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 23:42:25 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

void	ft_eating(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print(philo, ft_time(), "has taken a fork");
	sem_wait(philo->data->forks);
	ft_print(philo, ft_time(), "has taken a fork");
	ft_print(philo, ft_time(), "is eating");
	if (!ft_usleep(philo, ft_time(), philo->data->time_to_eat))
	{
		ft_print(philo, ft_time(), NULL);
		exit(1);
	}
	philo->last_meal = ft_time();
	philo->meals += 1;
	if(philo->meals == philo->data->must_eat)
		exit(0);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print(philo, ft_time(), "is sleeping");
	if (!ft_usleep(philo, ft_time(), philo->data->time_to_sleep))
	{
		ft_print(philo, ft_time(), NULL);
		exit(1);
	}
}

void	ft_thinking(t_philo *philo)
{
	ft_print(philo, ft_time(), "is thinking");
}

void	routine(t_philo *philo)
{
	while (1)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
}
