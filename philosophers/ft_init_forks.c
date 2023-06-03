//
//  ft_create_mutex.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

pthread_mutex_t *ft_init_forks(int amount)
{
    pthread_mutex_t *forks;
    int             i;
    
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
