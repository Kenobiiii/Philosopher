/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:41:50 by paromero          #+#    #+#             */
/*   Updated: 2024/09/17 14:00:56 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlastr(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	rotate(t_stack **list)
{
	t_stack	*node;
	t_stack	**tmp;

	tmp = list;
	node = NULL;
	if (*list != NULL)
	{
		node = *list;
		*list = (*list)->next;
		node->next = NULL;
		ft_lstlastr(*list)->next = node;
	}
	list = tmp;
}

void	ra(t_stack **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	rb(t_stack **list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rr(t_stack **list_a, t_stack **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}
