//
//  main.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"


void ft_check_for_deaths(void *args)
{
	t_table     *table;

	table = (t_table *)args;
	while (1)
	{
		pthread_mutex_lock(&table->death_mutex);
		if (table->dead_philosopher_id)
		{
			pthread_mutex_unlock(&table->death_mutex);
			break;
		}
		pthread_mutex_unlock(&table->death_mutex);
	}
}

int main(int argc, const char **argv)
{
    t_config    config;
    t_table     table;
	// pthread_t	check_for_deaths;

    if (ft_init_config(argc, argv, &config) == FALSE)
        return (1);
    if (ft_init_table(config, &table) == FALSE)
        return (2);
    if (ft_start_threads(table) == FALSE)
        return (3);
    if (ft_wait_threads(table) == FALSE)
        return (4);
	// ft_check_for_deaths(&table);
    if (ft_destroy(&table) == FALSE)
        return (5);
    return (0);
}
