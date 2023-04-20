/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:21:04 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 23:44:24 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	pid_t	wait_pid;
	int		status;
	int		i;

	data = ft_init_data(argc, argv);
	if (!data)
		return (printf("data failed / invalid argument\n"), 1);
	sem_unlink("sem_philo");
	sem_unlink("sem_print");
	// sem_unlink("sem_finish");
	data->forks = sem_open("sem_philo", O_CREAT, 0666, data->nbr_of_philo);
	data->print = sem_open("sem_print", O_CREAT, 0666, 1);
	// data->finish = sem_open("sem_finish", O_CREAT, 0666, 1);
	i = 0;
	data->start = ft_time();
	while (i < data->nbr_of_philo)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid == 0)
		{
			data->philo[i].id = (i + 1);
			data->philo[i].last_meal = data->start;
			data->philo[i].meals = 0;
			data->philo[i].data = data;
			routine(&data->philo[i]);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < data->nbr_of_philo)
	{
		wait_pid = waitpid(data->philo[i].pid, &status, 0);
		if(status)
		{
			terminate_all(data);
			return 0;
		}
		else
			wait_for_all(data,wait_pid);
		i++;
	}
	// wait_pid = waitpid(-1, &status, 0);
	// if (status)
	// 	terminate_all(data);
	// else
	// 	wait_for_all(data, wait_pid);
	sem_close(data->forks);
	sem_close(data->print);
	sem_unlink("sem_philo");
	sem_unlink("sem_print");
	return (0);
}
