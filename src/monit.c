/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:17:07 by paromero          #+#    #+#             */
/*   Updated: 2024/10/16 12:29:05 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals_philo_had(philo) >= data->nb_meals)
		result = true;
	return (result);
}

int	philo_died(t_philo *philo)
{
	t_data	*data;
	int		result;

	data = philo->data;
	result = 0;
	pthread_mutex_lock(&philo->mut_last_eat_time);
	if ((get_time() - philo->last_eat_time) > data->die_time
		&& get_state(philo) != EATING)
	{
		set_state(philo, DEAD);
		result = 1;
	}
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (result);
}

void	notify_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = data->nb_philos;
	philos = data->philos;
	i = -1;
	while (++i < nb_philos)
		set_state(&philos[i], DEAD);
}

void	*monit_alive_rutine(void *av)
{
	t_data	*data;
	t_philo	*philos;
	int		i;
	int		nb_philos;

	data = (t_data *)av;
	philos = data->philos;
	nb_philos = data->nb_philos;
	i = -1;
	while (i++ < nb_philos && get_keep_iter(data))
	{
		if (philo_died(&philos[i]) && get_keep_iter(data))
		{
			printf("%lu %d has died\n",
				(get_time() - data->start_time), philos[i].id);
			set_keep_iter(data, false);
			notify_philos(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		if (get_keep_iter(data))
			usleep(500);
	}
	return (NULL);
}

void	*monit_full_rutine(void	*av)
{
	t_data	*data;
	int		i;
	int		nb_philos;
	bool	all_full;

	data = (t_data *)av;
	nb_philos = data->nb_philos;
	i = 0;
	while (get_keep_iter(data))
	{
		all_full = true;
		usleep(1000);
		i = 0;
		while (i < nb_philos)
		{
			if (!is_philo_full(data, &data->philos[i]))
			{
				all_full = false;
				break ;
			}
			i++;
		}
		if (all_full)
		{
			set_keep_iter(data, false);
			notify_philos(data);
		}
	}
	return (NULL);
}
