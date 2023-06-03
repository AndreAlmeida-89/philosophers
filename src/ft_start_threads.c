//
//  ft_start_threads.c
//  philosophers
//
//  Created by Andre Almeida on 30/05/23.
//

#include "philosophers.h"

int ft_start_threads(t_table table)
{
    int i = -1;
    while (++i < table.config.size)
        if (pthread_create(&table.philos[i].thread, NULL, ft_routine, &table.philos[i]) != 0)
            return (FALSE); // TODO: handle destroy
    return (TRUE);
}
