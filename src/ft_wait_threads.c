/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:48:50 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/04 09:49:18 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_wait_threads(t_table table)
{
	int	i;

	i = -1;
	while (++i < table.config.size)
	{
		if (pthread_join(table.philos[i].thread, NULL) != 0)
			return (FALSE);
	}
	return (TRUE);
}
