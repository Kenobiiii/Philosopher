/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:28:09 by paromero          #+#    #+#             */
/*   Updated: 2024/09/14 01:27:06 by paromero         ###   ########.fr       */
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
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef t_stack	*t_pointer;

void	ft_error(void);
void	check_args(int ac, char **av, t_stack **list);
void	ft_free(char **tokens);
void	assign_indexes(t_stack *list);
void    pb(t_stack **list1, t_stack **list2);
void    pa(t_stack **list1, t_stack **list2);
void    sa(t_stack **list);
void    sb(t_stack **list);
void    ss(t_stack **list1, t_stack **list2);
void    ra(t_stack **list);
void    rb(t_stack **list);
void    rr(t_stack **list1, t_stack **list2);
void    rra(t_stack **list);
void    rrb(t_stack **list);
void    rrr(t_stack **list1, t_stack **list2);



t_stack	*ft_lstlastr(t_stack *lst);

int		hasduplicates(t_stack *list);

#endif