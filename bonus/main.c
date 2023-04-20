/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:48:54 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/20 00:36:34 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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

void	routine(t_philo	*philo)
{
	while(1)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	exit(0);
}

void ft_wait_childes(t_philo *phs)
{
	pid_t pid;
	int status;
	t_philo *tmp;

	pid = waitpid(-1, &status, 0);
	tmp = phs;
	while(tmp)
	{
		if(status)
		{
			if(tmp->pid != pid)
				kill(tmp->pid, SIGINT);
		}
		else
		{
			if(tmp->pid != pid)
				waitpid(tmp->pid, NULL, 0);	
		}
		if(tmp == phs)
			break;	
	}
}


void	ft_forks(t_philo *philo, t_data	*data)
{
	t_philo *tmp;

	tmp = philo;
	data->start = ft_time();
	while(tmp)
	{
		tmp->pid = fork();
		if(tmp->pid == 0)
		{
			tmp->meals = 0;
			tmp->last_meal = data->start;
			routine(tmp);
			return ;
		}
		tmp = tmp->next;
		if (tmp == philo)
			break ;
	}
	ft_wait_childes(philo);
	sem_unlink("sem_ph");
	sem_unlink("sem_print");
}

int main(int	argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	data = init_data(argc, argv);
	if(!data)
		return 0;
	philo = create_philo(data);
	ft_forks(philo, data);
	return 0;
}