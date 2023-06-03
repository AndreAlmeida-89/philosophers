//
//  ft_init_table.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

int ft_init_table(t_config config, t_table *table)
{
    int i;
    table->forks = ft_init_forks(config.size);
    if (table->forks == NULL)
        return (FALSE);
    if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
        return (FALSE);
    table->config = config;
    i = -1;
    if (ft_init_philosophers(table) == FALSE)
        return (FALSE); // TODO: handle destroy
    table->dead_philosopher_id = 0;
    table->start_time = ft_now();
    return (TRUE);
}
