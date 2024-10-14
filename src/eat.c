/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:53:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 11:48:03 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takeforks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_f]);
	printf("%llu Philosopher %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->right_f]);
	printf("%llu Philosopher %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
}

int	eat(t_philo	*philo)
{
	takeforks(philo);
	if (get_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(&philo->mut_last_eat_time);
	printf("%llu Philosopher %d is eating\n",
		get_time() - philo->data->start_time, philo->id);
	philo->last_eat_time = (get_time() - philo->data->start_time);
	set_state(philo, EATING);
	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left_f]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_f]);
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (0);
}
