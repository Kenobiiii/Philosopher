/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:58:50 by paromero          #+#    #+#             */
/*   Updated: 2024/09/16 12:36:17 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_pos(t_stack *list)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = list;
	while (current != NULL)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

void	ft_pass(t_stack **list_a, t_stack **list_b)
{
	double	average;
	int		total;

	total = count_values(*list_a);
	*list_b = NULL;
	average = ft_average(*list_a);
	while (total > 3)
	{
		if ((*list_a)->index < average)
		{
			pb(list_a, list_b);
			total--;
		}
		else if (verify_index(*list_a, average) == 0)
		{
			total--;
			pb(list_a, list_b);
		}
		else
			ra(list_a);
	}
}

	int nearest_index(int index1, t_stack *list_a)
	{
		int index2;
		t_stack *compare;

		index2 = INT_MAX;
		compare = list_a;
		while (compare != NULL)
		{
			if (index1 < compare->index && compare->index < index2)
			{
				index2 = compare->index;
			}
			compare = compare->next;
		}
		return index2;
	}

void target_pos(t_stack *list_a, t_stack *list_b)
{
	t_stack *current;
	t_stack *compare;
	int		nearest;

	current = list_b;
	while (current != NULL)
	{
		nearest = nearest_index(current->index, list_a);
		compare = list_a;
		while (compare != NULL)
		{
			if (compare->index == nearest)
			{
				current->target_pos = compare->pos;
				break;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

// void	ft_costs(t_stack *list_a, t_stack *list_b)
// {
	
// }

void	ft_sorting(t_stack **list_a, t_stack **list_b)
{
	ft_pass(list_a, list_b);
	three_algorithm(list_a);
	assign_pos(*list_a);
	assign_pos(*list_b);
	target_pos(*list_a, *list_b);
	printf("Lista A:\n");
	printlist(*list_a);
	printf("Lista B:\n");
	printlist(*list_b);
	
}
