/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:49:32 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 17:31:38 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (ft_wait_threads(table) == FALSE)
		return (4);
	if (ft_destroy(&table) == FALSE)
		return (5);
	return (0);
}
