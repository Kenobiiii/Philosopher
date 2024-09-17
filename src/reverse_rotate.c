/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:03:51 by paromero          #+#    #+#             */
/*   Updated: 2024/09/17 14:00:31 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstunlast(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = NULL;
	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp->next;
		if (tmp2->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	reverse_rotate(t_stack **list)
{
	t_stack	*node;

	node = NULL;
	if (*list != NULL)
	{
		node = ft_lstlastr(*list);
		ft_lstunlast(*list)->next = NULL;
		node->next = *list;
		*list = node;
	}
}

void	rra(t_stack **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}

void	rrb(t_stack **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}

void	rrr(t_stack **list_a, t_stack **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}
