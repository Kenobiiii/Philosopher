/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:42:51 by paromero          #+#    #+#             */
/*   Updated: 2024/09/16 16:51:29 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

int	nearest_index(int index1, t_stack *list_a)
{
	int		index2;
	t_stack	*compare;

	index2 = INT_MAX;
	compare = list_a;
	while (compare != NULL)
	{
		if (index1 < compare->index && compare->index < index2)
		{
			index2 = compare->index;
		}
		compare = compare->next;
	}
	return (index2);
}

void	assign_pos(t_stack *list)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = list;
	while (current != NULL)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}
