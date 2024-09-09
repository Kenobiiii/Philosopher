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