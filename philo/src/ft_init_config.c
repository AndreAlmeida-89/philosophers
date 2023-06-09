/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:31:51 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/09 01:16:27 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_is_numeric(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			if (ft_isdigit(argv[i][j++]) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}

static int	ft_is_valig_config(t_config config, int argc)
{
	if (argc == 6 && config.number_of_meals < 0)
		return (FALSE);
	return (
		config.size > 0
		&& config.time_to_die > 0
		&& config.time_to_eat > 0
		&& config.time_to_sleep > 0);
}

int	ft_init_config(int argc, const char **argv, t_config *config)
{
	if ((argc != 5 && argc != 6)
		|| ft_is_numeric(argc, argv) == FALSE)
		return (FALSE);
	config->size = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		config->number_of_meals = ft_atoi(argv[5]);
	else
		config->number_of_meals = -1;
	if (ft_is_valig_config(*config, argc) == FALSE)
		return (FALSE);
	return (TRUE);
}
