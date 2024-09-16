/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:58:50 by paromero          #+#    #+#             */
/*   Updated: 2024/09/16 16:45:53 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	target_pos(t_stack *list_a, t_stack *list_b)
{
	t_stack	*current;
	t_stack	*compare;
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
				break ;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

void	ft_costs(t_stack *list)
{
	t_stack	*node;
	int		len;

	node = list;
	len = count_values(list);
	while (node)
	{
		if (node->pos > len / 2)
			node->cost = -1 * (len - node->pos);
		else
			node->cost = node->pos;
		node = node->next;
	}
}

void	ft_total_cost(t_stack *list_a, t_stack *list_b)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		tmp;

	node_b = list_b;
	while (list_b)
	{
		node_a = list_a;
		tmp = node_b->target_pos;
		while (tmp-- > node_a->pos)
			node_a = node_a->next;
		if ((node_b->cost > 0 && node_a->cost > 0)
			|| (node_b->cost < 0 && node_a->cost < 0))
		{
			if (ft_abs(node_b->cost) > ft_abs(node_a->cost))
				node_b->total_cost = ft_abs(node_b->cost);
			else
				node_b->total_cost = ft_abs(node_a->cost);
		}
		else
			node_b->total_cost = ft_abs(node_b->cost) + ft_abs(node_a->cost);
		node_b = node_b->next;
	}
}

void	ft_sorting(t_stack **list_a, t_stack **list_b)
{
	ft_pass(list_a, list_b);
	three_algorithm(list_a);
	assign_pos(*list_a);
	assign_pos(*list_b);
	target_pos(*list_a, *list_b);
	ft_costs(*list_a);
	ft_costs(*list_b);
	printf("Lista A:\n");
	printlist(*list_a);
	printf("Lista B:\n");
	printlist(*list_b);
}
