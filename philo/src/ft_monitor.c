/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:51:29 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/08 16:52:20 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_monitor(void *arg)
{
	t_table		*t;
	int			i;
	int			finished_philos;

	t = (t_table *)arg;
	finished_philos = 0;
	i = 0;
	while (i < t->config.size && usleep(100) == 0)
	{
		pthread_mutex_lock(&t->death_mutex);
		if (t->has_dead_philo || finished_philos == t->config.size)
			return (pthread_mutex_unlock(&t->death_mutex), NULL);
		if (ft_now() - t->philos[i].last_meal_time > t->config.time_to_die)
		{
			t->has_dead_philo = TRUE;
			pthread_mutex_unlock(&t->death_mutex);
			return (ft_print_action(&t->philos[i], DIE), NULL);
		}
		if (t->philos[i].number_of_meals == 0)
			finished_philos++;
		pthread_mutex_unlock(&t->death_mutex);
		if (++i == t->config.size)
			i = 0;
	}
	return (NULL);
}
