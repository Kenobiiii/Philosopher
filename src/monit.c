/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:17:07 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 19:31:41 by paromero         ###   ########.fr       */
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

// void	*monit_alive_rutine(void *av)
// {
// 	t_data	*data;
// 	int		i;
// 	int		stop;

// 	stop = 0;
// 	data = (t_data *)av;
// 	while (!stop)
// 	{
// 		i = 0;
// 		while (i < data->nb_philos)
// 		{
// 			if (philo_died(&data->philos[i]) && stop)
// 			{
// 				notify_philos(data);
// 				stop = 1;
// 				break;
// 			}
// 			i++;
// 		}
// 		usleep(100);
// 	}
// 	return (0);
// }
void	*monit_alive_rutine(void *av)
{
	t_data	*data;
	t_philo	*philos;
	int		i;
	int		nb_philos;

	data = (t_data *)av;
	philos = data->philos;
	nb_philos = data->nb_philos;
	while (get_keep_iter(data)) // Continuar mientras se permita iterar
	{
		i = -1;
		while (++i < nb_philos)
		{
			if (philo_died(&philos[i]) && get_keep_iter(data))
			{
				// Notificar muerte del filósofo usando printf
				printf("%lu %d has died\n", 
					(get_time() - data->start_time), philos[i].id);

				set_keep_iter(data, false); // Detener iteración
				notify_philos(data); // Notificar a todos los filósofos
				break; // Romper el bucle interno
			}
			if (i == nb_philos - 1) // Reiniciar el índice si es el último
				i = -1;
		}
		usleep(1000); // Pausar un poco antes de la siguiente iteración
	}
	return (NULL);
}