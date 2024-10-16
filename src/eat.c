/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:53:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/16 12:17:08 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_l(t_philo *philo)
{
	if (philo_died(philo) || get_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_f);
	if (philo_died(philo) || get_state(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->left_f);
		return (1);
	}
	printf("%lu %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
	return (0);
}

int	take_r(t_philo *philo)
{
	if (philo_died(philo) || get_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_f);
	if (philo_died(philo) || get_state(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}
	printf("%lu %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
	return (0);
}

int	takeforks(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
		return (handle_one(philo));
	if (take_r(philo))
		return (1);
	if (take_l(philo))
	{
		pthread_mutex_unlock(philo->right_f);	
		return (1);
	}
	return (0);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}

int	eat(t_philo	*philo)
{
	if (takeforks(philo))
		return (1);
	if (philo_died(philo) || get_state(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}
	update_last_meal_time(philo);
	printf("%lu %d is eating\n",
		get_time() - philo->data->start_time, philo->id);
	set_state(philo, EATING);
	ft_usleep(philo->data->eat_time);
	pthread_mutex_lock(&philo->mut_nb_meals_had);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	return (0);
}
