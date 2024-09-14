/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:58:50 by paromero          #+#    #+#             */
/*   Updated: 2024/09/14 22:03:56 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_average(t_stack *list)
{
	int		sum;
	int		count;
	t_stack	*current;

	sum = 0;
	count = 0;
	current = list;
	while (current != NULL)
	{
		sum += current->index;
		count++;
		current = current->next;
	}
	if (count == 0)
		return (0);
	return ((double)sum / count);
}

int	verify_index(t_stack *list, double average)
{
	t_stack	*current;

	current = list;
	while (current != NULL)
	{
		if (current->index < average)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_pass(t_stack **list1, t_stack **list2)
{
	double	average;
	int		total;

	total = count_values(*list1);
	*list2 = NULL;
	average = ft_average(*list1);
	while (total > 3)
	{
		if ((*list1)->index < average)
		{
			pb(list1, list2);
			total--;
		}
		else if (verify_index(*list1, average) == 0)
		{
			total--;
			pb(list1, list2);
		}
		else
			ra(list1);
	}
}

void	ft_sorting(t_stack **list1, t_stack **list2)
{
	ft_pass(list1, list2);
	printlist(*list1);
	printlist(*list2);
	if (count_values(*list1) == 3)
		three_algorithm(list1);
}
