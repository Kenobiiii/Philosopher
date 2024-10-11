/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:17:07 by paromero          #+#    #+#             */
/*   Updated: 2024/10/11 19:01:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monit_alive_rutine(void *av)
{
	t_data	*data;
	int		i;

	data = (t_data *)av;
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].mut_last_eat_time);
		if ((get_time() - data->philos[i].last_time_eat) > data->die_time)
		{
			printf("Philosopher %d has died\n", data->philos[i].id);
			pthread_mutex_unlock(&data->philos[i].mut_last_eat_time);
			// stop_sim(); por hacer
		}
		pthread_mutex_unlock(&data->philos[i].mut_last_eat_time);
		i++;
	}
}
