/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:42:10 by paromero          #+#    #+#             */
/*   Updated: 2024/06/19 10:42:10 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_arg(char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == ' ')
			i++;
		if (array[i] < '0' || array[i] > '9')
			ft_error();
		i++;
	}
}

void	various_args(int ac, char **av)
{
	int	j;
	int	i;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_args(int ac, char **av)
{
	if (ac == 2)
		one_arg(av[1]);
	else if (ac > 2)
		various_args(ac, av);
	else
		exit(EXIT_SUCCESS);
}
