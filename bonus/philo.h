/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:47:55 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/20 00:21:24 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	long long		start;
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	sem_t			*forks;
	sem_t			*print;
}					t_data;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	int				meals;
	long long		last_meal;
	struct s_data	*data;
	struct s_philo *next;
}					t_philo;

t_philo	*ft_create_ph(int id, t_data *data);
t_philo	*ft_addfront(t_philo *philo, t_philo *new);
long long	ft_time(void);
int	ft_usleep(t_philo *philo, long long time, int time_to_usleep);
t_data	*init_data(int argc, char **argv);
t_philo	*create_philo(t_data	*data);
int	ft_atoi(char *str);
void	ft_print(t_philo *philo, long long time, char *s);

#endif