/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:37:53 by paromero          #+#    #+#             */
/*   Updated: 2024/09/16 10:53:52 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **list_a, t_stack **list_b)
{
	t_stack	*node;

	node = NULL;
	if (*list_a != NULL)
	{
		node = *list_a;
		*list_a = (*list_a)->next;
		node->next = *list_b;
		*list_b = node;
	}
}

void	pb(t_stack **list_a, t_stack **list_b)
{
	push(list_a, list_b);
}

void	pa(t_stack **list_a, t_stack **list_b)
{
	push(list_b, list_a);
}
