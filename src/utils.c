/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:30:24 by paromero          #+#    #+#             */
/*   Updated: 2024/09/09 18:30:24 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j] != NULL)
	{
		free(tokens[j]);
		j++;
	}
	free(tokens);
}

void	assign_indexes(t_stack *list)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = list;
	while (current != NULL)
	{
		index = 1;
		compare = list;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	count_values(t_stack *list)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = list;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
