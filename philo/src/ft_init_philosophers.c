/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:36:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/04 09:36:54 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_philosophers(t_table *table)
{
	int	i;

	i = -1;
	table->philos = malloc(sizeof(t_philo) * table->config.size);
	if (table->philos == NULL)
		return (FALSE);
	while (++i < table->config.size)
	{
		table->philos[i].thread = 0;
		table->philos[i].number_of_meals = table->config.number_of_meals;
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].last_meal_time = ft_now();
		table->philos[i].left_fork = &table->forks[i];
		if (i == 0)
			table->philos[i].right_fork = &table->forks[table->config.size - 1];
		else
			table->philos[i].right_fork = &table->forks[i - 1];
	}
	return (TRUE);
}
