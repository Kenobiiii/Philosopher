/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:03:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/15 19:02:16 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	set_state(philo, SLEEPING);
	if (get_state(philo) == DEAD)
		return (1);
	printf("%lu %d is sleeping\n",
		get_time() - philo->data->start_time, philo->id);
	ft_usleep(philo->data->sleep_time);
	return (0);
}
