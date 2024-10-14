/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:17:07 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 17:26:31 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	monit_alive_rutine(void *av)
// {
// 	t_data	*data;
// 	int		i;

// 	data = (t_data *)av;
// 	i = 0;
// 	while (i < data->nb_philos)
// 	{
// 		pthread_mutex_lock(&data->philos[i].mut_last_eat_time);
// 		if ((get_time() - data->philos[i].last_time_eat) > data->die_time)
// 		{
// 			printf("Philosopher %d has died\n", data->philos[i].id);
// 			set_state(philo[i], state);
// 			pthread_mutex_unlock(&data->philos[i].mut_last_eat_time);
// 			// stop_sim(); por hacer
// 		}
// 		pthread_mutex_unlock(&data->philos[i].mut_last_eat_time);
// 		i++;
// 	}
// }

int	philo_died(t_philo *philo)
{
	t_data	*data;
	int result;

	data = philo->data;
	result = 0;
	pthread_mutex_lock(philo->mut_last_eat_time);
	if ((get_time() - philo->last_eat_time) > data->die_time
		&& philo->state != EATING)
	{
		set_state(philo, DEAD);
		result = 1;
	}
	pthread_mutex_unlock(philo->mut_last_eat_time);
	return (result);
}
