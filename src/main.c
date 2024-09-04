/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:54:40 by paromero          #+#    #+#             */
/*   Updated: 2024/06/17 20:54:40 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printList(t_stack* node) {
    while (node != NULL) {
        printf("Value: %d, Index: %d, Pos: %d -> ", 
               node->value, node->index, node->pos);
        node = node->next;
    }
    printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_stack	*A;

	A = NULL;
	check_args(ac, av, &A);
	hasduplicates(A);
	printList(A);
	return (0);
}
