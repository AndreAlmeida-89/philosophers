/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:40:23 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/09 01:03:44 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_eat(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
	}
	ft_print_action(p, TAKE_FORK);
	ft_print_action(p, TAKE_FORK);
	ft_print_action(p, EAT);
	pthread_mutex_lock(&p->table->death_mutex);
	p->last_meal_time = ft_now();
	p->number_of_meals--;
	pthread_mutex_unlock(&p->table->death_mutex);
	ft_wait(p->table->config.time_to_eat, p->table);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return (TRUE);
}

static void	ft_single_philosopher(t_philo *p)
{
	ft_print_action(p, TAKE_FORK);
	usleep(p->table->config.time_to_die * 1000);
}

void	*ft_routine(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	if (p->table->config.size == 1)
		return (ft_single_philosopher(p), NULL);
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&p->table->death_mutex);
		if (p->table->has_dead_philo || p->number_of_meals == 0)
			return (pthread_mutex_unlock(&p->table->death_mutex), NULL);
		pthread_mutex_unlock(&p->table->death_mutex);
		ft_eat(p);
		ft_print_action(p, SLEEP);
		ft_wait(p->table->config.time_to_sleep, p->table);
		ft_print_action(p, THINK);
	}
	return (NULL);
}
