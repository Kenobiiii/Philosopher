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

// void	one_arg(char *array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i] != '\0')
// 	{
// 		if (array[i] == ' ')
// 			i++;
// 		if (array[i] < '0' || array[i] > '9')
// 			ft_error();
// 		i++;
// 	}
// }

// void	various_args(int ac, char **av)
// {
// 	int	j;1
// 	int	i;

// 	i = 1;
// 	while (i < ac)
// 	{
// 		j = 0;
// 		while (av[i][j] != '\0')
// 		{
// 			if (av[1][j] == ' ')
// 				ft_error();
// 			else if (av[i][j] < '0' || av[i][j] > '9')
// 				ft_error();
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	check_args(int ac, char **av)
// {
// 	if (ac == 2)
// 		one_arg(av[1]);
// 	else if (ac > 2)
// 		various_args(ac, av);
// 	else
// 		exit(EXIT_SUCCESS);
// }
// Función para verificar argumentos y crear la lista enlazada

void ft_add(t_stack** head_ref, int new_value, int new_pos)
{
	t_stack* new_node = (t_stack*)malloc(sizeof(t_stack));
	t_stack* last = *head_ref;

	new_node->value = new_value;
	new_node->pos = new_pos;
	new_node->index = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	int index = 1;
	while (last->next != NULL) {
		last = last->next;
		index++;
	}
	new_node->index = index;
	last->next = new_node;
}

int hasDuplicates(t_stack* head) {
	t_stack* current = head;
	t_stack* checker;

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
	return 0;
}

void one_arg(char *array, t_stack **head)
{
	int i = 0;
	char *token = strtok(array, " ");
	int pos = 0;

	while (token != NULL) {
		for (i = 0; token[i] != '\0'; i++)
		{
			if (token[i] < '0' || token[i] > '9')
			{
				ft_error();
			}
		}
		ft_add(head, atoi(token), pos);
		pos++;
		token = strtok(NULL, " ");
	}
}

void various_args(int ac, char **av, t_stack **head) {
	int i;
	int j;
	int pos;

	pos = 0;
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				ft_error();
			}
			j++;
		}
		ft_add(head, ft_atoi(av[i]), pos);
		pos++;
		i++;
	}
}

void	check_args(int ac, char **av, t_stack **head)
{
	if (ac == 2)
	{
		one_arg(av[1], head);
	}
	else if (ac > 2)
	{
		various_args(ac, av, head);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	t_stack	*head;

	head = NULL;
	check_args(ac, av, &head);
	hasDuplicates(head);
	return (0);
}
