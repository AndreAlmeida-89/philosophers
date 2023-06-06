/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:31:35 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 19:52:03 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_destroy_threads(t_table *table)
{
	if (table->forks)
		free(table->philos);
}

static void	ft_destroy_mutex(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	if (!table->forks)
		return ;
	i = -1;
	while (++i < table->config.size)
		if (pthread_mutex_destroy(&table->forks[i]) != 0)
			break ;
	free(table->forks);
}

void	ft_destroy(t_table *table)
{
	ft_destroy_threads(table);
	ft_destroy_mutex(table);
}
