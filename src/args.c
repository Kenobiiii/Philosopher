/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:42:10 by paromero          #+#    #+#             */
/*   Updated: 2024/06/19 10:42:10 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add(t_stack	**list_ref, int new_value, int new_pos)
{
	t_stack	*new_node;
	t_stack	*last;
	int		index;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	last = *list_ref;
	new_node->value = new_value;
	new_node->pos = new_pos;
	if (*list_ref == NULL)
	{
		*list_ref = new_node;
		return ;
	}
	index = 1;
	while (last->next != NULL)
	{
		last = last->next;
		index++;
	}
	new_node->index = index;
	last->next = new_node;
}

int	hasduplicates(t_stack	*list)
{
	t_stack	*current;
	t_stack	*checker;

	current = list;
	while (current != NULL && current->next != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
			{
				ft_error();
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
void ft_free(char **tokens)
{
	int j;

	j = 0;
	while (tokens[j] != NULL)
	{
		free(tokens[j]);
		j++;
	}
	free(tokens);
}

void	one_arg(char *array, t_stack **list)
{
	char	**tokens;
	char	*token;
	int		j;
	int		i;

	tokens = ft_split(array, ' ');
	j = 0;
	if (!tokens)
		ft_error();
	while (tokens[j] != NULL)
	{
		token = tokens[j];
		i = 0;
		while (token[i] != '\0')
		{
			if (!isdigit(token[i]))
				ft_error();
			i++;
		}
		ft_add(list, ft_atoi(token), j);
		j++;
	}
	j = 0;
	ft_free(tokens);
}

void	various_args(int ac, char **av, t_stack **list)
{
	int	i;
	int	j;
	int	pos;

	pos = 1;
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			if (!isdigit(av[i][j]))
			{
				ft_error();
			}
			j++;
		}
		j = 0;
		ft_add(list, ft_atoi(av[i]), pos);
		pos++;
		i++;
	}
}

void	check_args(int ac, char **av, t_stack **list)
{
	if (ac == 2)
	{
		one_arg(av[1], list);
	}
	else if (ac > 2)
	{
		various_args(ac, av, list);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}