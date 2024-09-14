/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:45:04 by paromero          #+#    #+#             */
/*   Updated: 2024/09/14 21:59:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_higher_middle(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *list;
	node2 = node1->next;
	node3 = node2->next;
	if (node3->index > node2->index)
		printf("terminado");
	else if (node3->index < node2->index)
	{
		if (node1->index < node3->index)
		{
			rra(list);
			sa(list);
		}
		else
			rra(list);
	}
}

void	ft_rest(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *list;
	node2 = node1->next;
	node3 = node2->next;
	if (node1->index > node3->index)
	{
		if (node3->index > node2->index)
			ra(list);
		else
		{
			ra(list);
			sa(list);
		}
	}
	else if (node1->index < node3->index
		&& node1->index > node2->index)
		sa(list);
}

void	three_algorithm(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *list;
	node2 = node1->next;
	node3 = node2->next;
	if (node2->index > node1->index)
		ft_higher_middle(list);
	else if (node1->index > node2->index)
		ft_rest(list);
}
