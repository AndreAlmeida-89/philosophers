/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:38:22 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 09:57:47 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_wait(int milliseconds, t_philo *p)
{
	time_t	start;

	start = ft_now();
	while (ft_now() < start + milliseconds)
	{
		pthread_mutex_lock(&p->table->death_mutex);
		if (p->table->dead_philosopher_id)
		{
			pthread_mutex_unlock(&p->table->death_mutex);
			return (FALSE);
		}
		if (ft_now() - p->last_meal_time > p->table->config.time_to_die)
		{
			p->table->dead_philosopher_id = p->id;
			pthread_mutex_unlock(&p->table->death_mutex);
			ft_print_action(p, DIE);
			return (FALSE);
		}
		pthread_mutex_unlock(&p->table->death_mutex);
		usleep(100);
	}
	return (TRUE);
}
