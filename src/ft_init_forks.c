/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:32:43 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/04 09:54:30 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*ft_init_forks(int amount)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * amount);
	if (!forks)
		return (NULL);
	i = -1;
	while (++i < amount)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (--i)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (NULL);
		}
	}
	return (forks);
}
