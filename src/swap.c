/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:14:36 by paromero          #+#    #+#             */
/*   Updated: 2024/09/16 10:53:52 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*node;

	node = NULL;
	if (*list != NULL)
	{
		node = *list;
		*list = (*list)->next;
		node->next = (*list)->next;
		(*list)->next = node;
	}
}

void	sa(t_stack **list)
{
	swap(list);
}

void	sb(t_stack **list)
{
	swap(list);
}

void	ss(t_stack **list_a, t_stack **list_b)
{
	swap(list_a);
	swap(list_b);
}
