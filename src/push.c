/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:37:53 by paromero          #+#    #+#             */
/*   Updated: 2024/09/14 12:19:40 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **list1, t_stack **list2)
{
	t_stack	*node;

	node = NULL;
	if (*list1 != NULL)
	{
		node = *list1;
		*list1 = (*list1)->next;
		node->next = *list2;
		*list2 = node;
	}
}

void	pb(t_stack **list1, t_stack **list2)
{
	push(list1, list2);
}

void	pa(t_stack **list1, t_stack **list2)
{
	push(list2, list1);
}
