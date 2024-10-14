/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:03:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 11:26:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	set_state(philo, SLEEPING);
	printf("%llu Philosopher %d is sleeping\n",
		get_time - philo->data->start_time, philo->id);
	usleep(philo->data->sleep_time * 1000);
}
