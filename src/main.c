/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:54:40 by paromero          #+#    #+#             */
/*   Updated: 2024/06/17 20:54:40 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *node)
{
	while (node != NULL)
	{
		ft_printf("Value: %d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_args(ac, av, &a);
	if (count_values(a) == 3)
		three_algorithm(&a);
	else
	{
		ft_sorting(&a, &b);
	}
		//pb(&a, &b);
	ft_printf("A list\n");
	printlist(a);
	ft_printf("B list\n");
	printlist(b);
	return (0);
}
