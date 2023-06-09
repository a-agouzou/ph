/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:07:57 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 20:02:52 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_philo *philo, long long time, int time_to_usleep)
{
	while (ft_time() - time < time_to_usleep)
	{
		if (ft_time() - philo->last_meal > philo->data->time_to_die)
			return (0);
		usleep(500);
	}
	return (1);
}

void	ft_print(t_philo *philo, long long time, char *s)
{
	sem_wait(philo->data->print);
	if (!s)
	{
		printf("%lld %d %s\n", ft_time() - philo->data->start, philo->id,
			"died");
		return ;
	}
	printf("%lld %d %s\n", (time - philo->data->start), philo->id, s);
	sem_post(philo->data->print);
}

int	ft_atoi(char *str)
{
	int	res;
	int	signe;
	int	i;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((res * signe));
}
