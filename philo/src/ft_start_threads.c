/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:41:13 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/05 17:35:33 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_start_threads(t_table table)
{
	int	i;

	i = -1;
	while (++i < table.config.size)
		if (pthread_create(
				&table.philos[i].thread,
				NULL,
				ft_routine,
				&table.philos[i]) != 0)
			return (FALSE);
	return (TRUE);
}
