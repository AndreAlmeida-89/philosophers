//
//  ft_wait_threads.c
//  philosophers
//
//  Created by Andre Almeida on 30/05/23.
//

#include "philosophers.h"

int ft_wait_threads(t_table table)
{
    int i;
    
    i = -1;
    while (++i < table.config.size)
    {
        if (pthread_join(table.philos[i].thread, NULL) != 0)
            return (FALSE);
//        if (pthread_detach(table.philos[i].thread) != 0)
//            return (FALSE);
    }
    return (TRUE);
}
