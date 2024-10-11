/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:53:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/11 19:02:22 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_f]);
	pthread_mutex_lock(&philo->data->forks[philo->right_f]);
	pthread_mutex_lock(&philo->mut_last_eat_time);
	printf("%llu Philosopher %d is eating",
		get_time() - philo->data->start_time, philo->id);
	philo->last_eat_time = (get_time() - philo->data->start_time);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->data->forks[philo->left_f]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_f]);
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}
