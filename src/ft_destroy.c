//
//  ft_destroy.c
//  philosophers
//
//  Created by Andre Almeida on 30/05/23.
//

#include "philosophers.h"

int ft_destroy_threads(t_table *table)
{
    int i;
    
    i= -1;
    while (++i < table->config.size)
        pthread_detach(table->philos[i].thread);
    free(table->philos);
    return (TRUE);
}

int ft_destroy_mutex(t_table *table)
{
    int i;
    
    i= -1;
    while (++i < table->config.size)
    if (pthread_mutex_destroy(&table->forks[i]) != 0)
    {
        free(table->forks);
        return (FALSE);
    }
    free(table->forks);
    return (TRUE);
}


int ft_destroy(t_table *table)
{
    return (ft_destroy_threads(table) && ft_destroy_mutex(table));
}
