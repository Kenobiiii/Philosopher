/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:58:50 by paromero          #+#    #+#             */
/*   Updated: 2024/09/15 13:45:30 by paromero         ###   ########.fr       */
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
int	nearest_index(t_stack *list1, t_stack *list2)
{
	int index;
	t_stack *current;
	t_stack	*compare;

	index = 1;
	current = list2;
	while (current != NULL)
	{
		compare = list1;
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

void	target_pos(t_stack *list1, t_stack *list2)
{
	t_stack	*current;
	t_stack	*compare;

	current = list2;
	while (current != NULL)
	{
		compare = list1;
		printf("%d\n", nearest_index(list1, list2));
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


void	ft_sorting(t_stack **list1, t_stack **list2)
{
	ft_pass(list1, list2);
	three_algorithm(list1);
	assign_pos(*list1);
	assign_pos(*list2);
	target_pos(*list1, *list2);
	printf("Lista A:\n");
	printlist(*list1);
	printf("Lista B:\n");
	printlist(*list2);
	
}
