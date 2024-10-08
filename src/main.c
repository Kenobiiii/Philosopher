/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:19:45 by paromero          #+#    #+#             */
/*   Updated: 2024/10/08 19:28:23 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher(int ac, char **av)
{
	t_data	data;

	if (init_data(&data, ac, av) != 0)
		return (MALLOC_ERROR);
	return (0);
}

int	main(int ac, char **av)
{
	if (check_input(ac, av) != 0)
	{
		ft_format();
		return (WRONG_INPUT);
	}
	if (philosopher(ac, av) != 0)
	{
		return (MALLOC_ERROR);
	}
	return (0);
}