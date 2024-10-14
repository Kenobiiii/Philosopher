/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:59:00 by paromero          #+#    #+#             */
/*   Updated: 2024/10/14 11:26:38 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rutine(void	*av)
{
	t_philo	*philo;

	philo = (t_philo *)av;
	while ()
	{
		eat(philo);
		if (philo->state == DEAD)
			break;
		ft_sleep(philo);
		if (philo->state == DEAD)
			break;
		think(philo);
	}
}
