/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:49:32 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/06 15:41:26 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	ft_monitor(t_table *t)
// {
// 	int		i;
// 	int		finished;
// 	t_philo	*p;

// 	finished = 0;
// 	while (1)
// 	{
// 		i = -1;
// 		while (++i < t->config.size)
// 		{
// 			p = t->philos + i;
// 			if (ft_now() - p->last_meal_time >= t->config.time_to_die)
// 			{
// 				pthread_mutex_lock(&t->print_mutex);
// 				printf("DIE FROM MONITOR\n");
// 				pthread_mutex_unlock(&t->print_mutex);
// 				return ;
// 			}
// 			if (p->number_of_meals == 0 && p->number_of_meals--)
// 				finished++;
// 			if (finished == t->config.size - 1)
// 				return ;
// 		}
// 	}
// }

int	main(int argc, const char **argv)
{
	t_config	config;
	t_table		table;

	if (ft_init_config(argc, argv, &config) == FALSE)
		return (1);
	if (ft_init_table(config, &table) == FALSE)
		return (2);
	if (ft_start_threads(table) == FALSE)
		return (3);
	// ft_monitor(&table);
	if (ft_wait_threads(table) == FALSE)
		return (4);
	ft_destroy(&table);
	return (0);
}
