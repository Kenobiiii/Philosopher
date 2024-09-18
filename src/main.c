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

int	ft_push_atoi(const char *str)
{
	int		negative;
	long	number;

	number = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number != 0)
			number *= 10;
		number += (*str - '0') * negative;
		str ++;
	}
	if (number > INT_MAX || number < INT_MIN)
		ft_error();
	return ((int)number);
}

void	ft_free_list(t_stack *list)
{
	t_stack	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	two_algorithm(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *list;
	node2 = node1->next;
	if (node1->index > node2->index)
		sa(list);
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
	else if (count_values(a) == 2)
		two_algorithm(&a);
	else if (count_values(a) > 3)
	{
		ft_pass(&a, &b);
		three_algorithm(&a);
		ft_sorting(&a, &b);
	}
	ft_free_list(a);
	return (0);
}
