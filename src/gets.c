/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:24:50 by paromero          #+#    #+#             */
/*   Updated: 2024/10/16 11:58:04 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_keep_iter(t_data *data)
{
	bool	keep_iter;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iter = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iter);
}

t_state	get_state(t_philo *philo)
{
	t_state	state;
	
	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}