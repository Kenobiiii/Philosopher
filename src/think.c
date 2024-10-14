/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:28:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 18:18:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	think(t_philo *philo)
{
	set_state(philo, THINKING);
	if (get_state(philo) == DEAD)
		return (1);
	printf("%lu Philosopher %d is thinking",
		get_time() - philo->data->start_time, philo->id);
	return (0);
}
