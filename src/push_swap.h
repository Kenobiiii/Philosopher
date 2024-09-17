/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:28:09 by paromero          #+#    #+#             */
/*   Updated: 2024/09/17 13:56:05 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost;
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

typedef t_stack	*t_pointer;

void	ft_error(void);
void	check_args(int ac, char **av, t_stack **list);
void	ft_free(char **tokens);
void	assign_indexes(t_stack *list);
void	pb(t_stack **list_a, t_stack **list_b);
void	pa(t_stack **list_a, t_stack **list_b);
void	sa(t_stack **list);
void	sb(t_stack **list);
void	ss(t_stack **list_a, t_stack **list_b);
void	ra(t_stack **list);
void	rb(t_stack **list);
void	rr(t_stack **list_a, t_stack **list_b);
void	rra(t_stack **list);
void	rrb(t_stack **list);
void	rrr(t_stack **list_a, t_stack **list_b);
void	three_algorithm(t_stack **list);
void	ft_sorting(t_stack **list_a, t_stack **list_b);
void	assign_pos(t_stack *list);
void	ft_total_cost(t_stack **list_a, t_stack **list_b);
void	ft_same_sign(t_stack *node_a, t_stack *node_b);
void	ft_pass(t_stack **list_a, t_stack **list_b);
void	final_sort(t_stack **list_a);
void	ft_different_sign(t_stack **list_a, t_stack **list_b,
			t_stack *node_a, t_stack *node_b);

t_stack	*ft_lstlastr(t_stack *lst);

int		hasduplicates(t_stack *list);
int		count_values(t_stack *list);
int		verify_index(t_stack *list, double average);
int		ft_abs(int nbr);
int		nearest_index(int index1, t_stack *list_a);
int		ft_lowest_cost(t_stack *list);
int		find_pos_first(t_stack	*list);

double	ft_average(t_stack *list);

void	printlist(t_stack *node);

#endif