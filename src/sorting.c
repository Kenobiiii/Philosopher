/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:58:50 by paromero          #+#    #+#             */
/*   Updated: 2024/09/16 10:53:57 by paromero         ###   ########.fr       */
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
int	nearest_index(t_stack *list_a, t_stack *list_b)
{
	int index;
	t_stack *current;
	t_stack	*compare;

	index = 1;
	current = list_b;
	while (current != NULL)
	{
		compare = list_a;
		while (compare != NULL)
		{
			if (current->index > compare->index)
			{
				if (index < compare->index)
				{
					printf("indice: %d\n", compare->index);
					index = compare->index;
				}
				else
					index = compare->index;
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (index);
}

void	target_pos(t_stack *list_a, t_stack *list_b)
{
	t_stack	*current;
	t_stack	*compare;

	current = list_b;
	while (current != NULL)
	{
		compare = list_a;
		printf("%d\n", nearest_index(list_a, list_b));
		while (compare != NULL)
		{
			if (compare->index > current->index)
			{
				current->target_pos = compare->pos;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}


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
