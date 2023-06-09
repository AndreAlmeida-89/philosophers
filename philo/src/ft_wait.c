/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:38:22 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/09 01:04:46 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_wait(int milliseconds, t_table *t)
{
	time_t	start;

	start = ft_now();
	while (ft_now() < start + milliseconds)
	{
		pthread_mutex_lock(&t->death_mutex);
		if (t->has_dead_philo)
			return (pthread_mutex_unlock(&t->death_mutex), FALSE);
		pthread_mutex_unlock(&t->death_mutex);
		usleep(100);
	}
	return (TRUE);
}
