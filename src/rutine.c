/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:59:00 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 18:17:51 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*rutine(void	*av)
{
	t_philo	*philo;

	philo = (t_philo *)av;
	while (get_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break;
		if (philo->state == DEAD)
			break;
		if (ft_sleep(philo) != 0)
			break;
		if (philo->state == DEAD)
			break;
		if (think(philo) != 0)
			break;
	}
	return (0);
}
