/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:53:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 17:36:33 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_l(t_philo *philo)
{
	if (philo_died(philo) || get_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_f);
	printf("%lu Philosopher %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
	return (0);
}

int	take_r(t_philo *philo)
{
	if (philo_died(philo) || get_state(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->left_f);	
		return (1);
	}
	pthread_mutex_lock(philo->right_f);
	printf("%lu Philosopher %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
	return (0);
}

int	takeforks(t_philo *philo)
{
	if (take_l(philo))
		return (1);
	if (take_r(philo))
		return (1);
	return (0);
}

int	eat(t_philo	*philo)
{
	if (takeforks(philo))
		return (1);
	pthread_mutex_lock(&philo->mut_last_eat_time);
	printf("%lu Philosopher %d is eating\n",
		get_time() - philo->data->start_time, philo->id);
	philo->last_eat_time = (get_time() - philo->data->start_time);
	set_state(philo, EATING);
	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (0);
}
