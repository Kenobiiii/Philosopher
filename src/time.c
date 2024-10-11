/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:19:29 by paromero          #+#    #+#             */
/*   Updated: 2024/10/11 18:34:38 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

u_int64_t	get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}