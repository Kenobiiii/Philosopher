/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:17:07 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 18:17:28 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	t_data	*data;
	int result;

	data = philo->data;
	result = 0;
	pthread_mutex_lock(&philo->mut_last_eat_time);
	if ((get_time() - philo->last_eat_time) > data->die_time
		&& philo->state != EATING)
	{
		set_state(philo, DEAD);
		result = 1;
	}
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (result);
}

void	notify_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philos)
	{
		set_state(&data->philos[i], DEAD);
		i++;
	}
}

void	*monit_alive_rutine(void *av)
{
	t_data	*data;
	int		i;
	int		stop;

	data = (t_data *)av;
	while (true)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (philo_died(&data->philos[i]))
			{
				notify_philos(data);
				stop = 1;
			}
			i++;
		}
		if (stop == 1)
			break;
		usleep(100);
	}
	return (0);
}

