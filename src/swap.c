/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:14:36 by paromero          #+#    #+#             */
/*   Updated: 2024/09/14 00:22:25 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack **list)
{
    t_stack *node;

    node = NULL;
    if (*list != NULL)
    {
        node = *list;
        *list = (*list)->next;
        node->next = (*list)->next;
        (*list)->next = node;
    }
}

void    sa(t_stack **list)
{
    swap(list);
}

void    sb(t_stack **list)
{
    swap(list);
}