/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:07:05 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 11:09:58 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_state(t_philo *philo, t_state state)
{
	ptherad_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		&philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}
