/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:40:23 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 09:59:30 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	pthread_mutex_lock(p->left_fork);
	ft_print_action(p, TAKE_FORK);
	ft_print_action(p, TAKE_FORK);
	ft_print_action(p, EAT);
	p->last_meal_time = ft_now();
	if (ft_wait(p->table->config.time_to_eat, p) == FALSE)
	{
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);
		return (FALSE);
	}
	p->number_of_meals--;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return (TRUE);
}

static void	ft_single_philosopher(t_philo *p)
{
	ft_print_action(p, TAKE_FORK);
	usleep(p->table->config.time_to_eat * 1000);
	ft_print_action(p, DIE);
}

void	*ft_routine(void *arg)
{
	t_philo	*p;
	int		should_eat_infinitely;

	p = (t_philo *)arg;
	should_eat_infinitely = p->number_of_meals == 0;
	if (p->table->config.size == 1)
	{
		ft_single_philosopher(p);
		return (NULL);
	}
	while (should_eat_infinitely || p->number_of_meals)
	{
		if (ft_eat(p) == FALSE)
			break ;
		ft_print_action(p, SLEEP);
		if (ft_wait(p->table->config.time_to_sleep, p) == FALSE)
			break ;
		ft_print_action(p, THINK);
	}
	return (NULL);
}
