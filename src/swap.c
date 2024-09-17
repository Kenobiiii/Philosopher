/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:14:36 by paromero          #+#    #+#             */
/*   Updated: 2024/09/17 14:01:34 by paromero         ###   ########.fr       */
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
	ft_printf("sa\n");
}

void	sb(t_stack **list)
{
	swap(list);
	ft_printf("sb\n");
}

void	ss(t_stack **list_a, t_stack **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
