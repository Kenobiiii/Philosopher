/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:47:54 by paromero          #+#    #+#             */
/*   Updated: 2024/10/11 19:00:44 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_format(void)
{
	printf("Format:\n");
	printf("./philo ");
	printf("Number of philosophers, ");
	printf("time to die, ");
	printf("time to eat, ");
	printf("time to sleep");
	printf(" (Optional) ");
	printf("N times each philo eats\n");
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_is_num(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] != '\0')
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				return (WRONG_INPUT);
			i++;
		}
		j++;
	}
	return (0);
}

int	wrong_input_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (WRONG_INPUT);
	if (ft_atoi(av[i]) < 1 || ft_atoi(av[i]) > 200)
		return (WRONG_INPUT);
	i++;
	while (i < 5)
	{
		if (ft_atoi(av[i]) < 60)
			return (WRONG_INPUT);
		i++;
	}
	return (0);
}

int	check_input(int ac, char **av)
{
	if (ac < 5)
		return (WRONG_INPUT);
	if (ac > 6)
		return (WRONG_INPUT);
	if (ft_is_num(ac, av) != 0)
		return (WRONG_INPUT);
	if (wrong_input_check(ac, av))
		return (WRONG_INPUT);
	return (0);
}
