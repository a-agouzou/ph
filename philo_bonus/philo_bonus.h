/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:22:17 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 23:27:13 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_philo;

typedef struct s_data
{
	long long		start;
	int				nbr_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				time_to_die;
	int				must_eat;
	sem_t			*finish;
	sem_t			*forks;
	sem_t			*print;
	struct s_philo	*philo;
}					t_data;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	int				meals;
	long long		last_meal;
	struct s_data	*data;
}					t_philo;

int					ft_atoi(char *str);
void				ft_print(t_philo *philo, long long time, char *s);
long long			ft_time(void);
int					ft_usleep(t_philo *philo, long long time,
						int time_to_usleep);
void				routine(t_philo *philo);
t_data				*ft_init_data(int argc, char **argv);
void				terminate_all(t_data *data);
void				wait_for_all(t_data *data, pid_t wait);
#endif