//
//  ft_routine.c
//  philosophers
//
//  Created by Andre Almeida on 30/05/23.
//

#include "philosophers.h"

void *ft_routine(void *arg)
{
    t_philo *p = (t_philo *)arg;
    pthread_mutex_lock(p->left_fork);
    pthread_mutex_lock(p->right_fork);
    printf("Philo %d is eating\n", p->id);
    ft_msleep(p->table->config.time_to_sleep);
    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
    return (NULL);
}
