/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:19:45 by paromero          #+#    #+#             */
/*   Updated: 2024/10/15 19:38:26 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
		int	i;
	int	nb_philos;

	nb_philos = data->nb_philos;
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}

int	join_threads(t_data *data)
{
	int i;

	i = 0;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (i < data->nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	philosopher(int ac, char **av)
{
	t_data	data;

	if (init_data(&data, ac, av) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	init_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

int	main(int ac, char **av)
{
	if (check_input(ac, av) != 0)
	{
		ft_format();
		return (WRONG_INPUT);
	}
	if (philosopher(ac, av) != 0)
	{
		return (MALLOC_ERROR);
	}
	return (0);
}
