/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:07:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/17 11:59:47 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	nb_meals_option(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

void	set_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

void	set_keep_iter(t_data *data, bool state)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = state;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(100);
}

int	handle_one(t_philo *philo)
{
	take_l(philo);
	ft_usleep(philo->data->die_time);
	set_state(philo, DEAD);
	pthread_mutex_unlock(philo->left_f);
	return (1);
}
