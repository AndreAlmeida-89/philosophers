/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:37:04 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/04 10:01:49 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_table(t_config config, t_table *table)
{
	table->forks = ft_init_forks(config.size);
	if (table->forks == NULL)
		return (FALSE);
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (FALSE);
	table->config = config;
	if (ft_init_philosophers(table) == FALSE)
		return (FALSE);
	table->dead_philosopher_id = 0;
	table->start_time = ft_now();
	return (TRUE);
}
