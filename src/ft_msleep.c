//
//  ft_msleep.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

void	ft_msleep(int milliseconds)
{
    usleep(milliseconds * 1000);
}

int	ft_wait(int milliseconds, t_table *table)
{
	// time_t	start;

	// start = ft_now();
	// while (1)
	// {
	// 	pthread_mutex_lock(&table->death_mutex);
	// 	if (ft_now() > start + milliseconds || table->dead_philosopher_id)
	// 	{
	// 		pthread_mutex_unlock(&table->death_mutex);
	// 		return (FALSE);
	// 	}
	// 	pthread_mutex_unlock(&table->death_mutex);
	// 	usleep(100);
	// }
	// return (TRUE);

	time_t	start;

	start = ft_now();
	while (1)
	{
		if (ft_now() > start + milliseconds)
		{
			break;
		}
		usleep(100);
	}
	table++;
	return (TRUE);
}