/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:07:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 19:25:40 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

t_state	get_state(t_philo *philo)
{
	t_state	state;
	
	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

bool	get_keep_iter(t_data *data)
{
	bool	keep_iter;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iter = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iter);
}

void	set_keep_iter(t_data *data, bool state)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = state;
	pthread_mutex_unlock(&data->mut_keep_iter);
}