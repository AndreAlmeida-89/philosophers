/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:39:32 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 10:00:29 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static const char	*ft_get_action_str(t_action action)
{
	if (action == EAT)
		return ("is eating");
	else if (action == SLEEP)
		return ("is sleeping");
	else if (action == THINK)
		return ("is thinking");
	else if (action == DIE)
		return ("died");
	else if (action == TAKE_FORK)
		return ("has taken fork");
	else
		return (NULL);
}

int	ft_print_action(t_philo *p, t_action action)
{
	pthread_mutex_lock(&p->table->death_mutex);
	if (action != DIE && p->table->dead_philosopher_id)
		return (pthread_mutex_unlock(&p->table->death_mutex));
	pthread_mutex_unlock(&p->table->death_mutex);
	pthread_mutex_lock(&p->table->print_mutex);
	printf("%ld\t%d %s\n",
		ft_now() - p->table->start_time,
		p->id,
		ft_get_action_str(action));
	pthread_mutex_unlock(&p->table->print_mutex);
	return (TRUE);
}
