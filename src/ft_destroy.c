/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:31:35 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 17:27:04 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_destroy_threads(t_table *table)
{
	if (!table->forks)
		return (FALSE);
	free(table->philos);
	return (TRUE);
}

static int	ft_destroy_mutex(t_table *table)
{
	int	i;

	if (pthread_mutex_destroy(&table->death_mutex) != 0)
		return (FALSE);
	if (pthread_mutex_destroy(&table->print_mutex) != 0)
		return (FALSE);
	i = -1;
	while (++i < table->config.size)
	{
		if (pthread_mutex_destroy(&table->forks[i]) != 0)
		{
			free(table->forks);
			return (FALSE);
		}
	}
	free(table->forks);
	return (TRUE);
}

int	ft_destroy(t_table *table)
{
	return (ft_destroy_threads(table) || ft_destroy_mutex(table));
}
