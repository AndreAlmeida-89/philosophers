//
//  ft.c
//  philosophers
//
//  Created by Andre Almeida on 30/05/23.
//

#include "philosophers.h"

int ft_init_philosopher(t_philo *p, t_table *table, int index)
{
    p->thread = malloc(sizeof(pthread_t));
    if (!p->thread)
        return (FALSE);
    p->table = table;
    p->id = index + 1;
    p->last_meal_time = table->start_time;
    p->left_fork = &table->forks[index];
    if (index == 0)
        p->right_fork = &table->forks[table->config.size - 1];
    else
        p->right_fork = &table->forks[index - 1];
    return (TRUE);
}
