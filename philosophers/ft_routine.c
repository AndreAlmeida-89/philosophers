//
//  ft_routine.c
//  philosophers
//
//  Created by Andre Almeida on 30/05/23.
//

#include "philosophers.h"

static void    ft_eat(t_philo *p)
{
    pthread_mutex_lock(p->right_fork);
    pthread_mutex_lock(p->left_fork);
    ft_print_action(p, TAKE_FORK);
    ft_print_action(p, TAKE_FORK);
    ft_print_action(p, EAT);
    ft_msleep(p->table->config.time_to_sleep);
    p->number_of_meals--;
    p->last_meal_time = ft_now();
    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
}

void *ft_routine(void *arg)
{
    t_philo *p;
    int     should_eat_infinitely;
    
    
    p = (t_philo *)arg;
    should_eat_infinitely = p->number_of_meals == 0;
    while (p->table->dead_philosopher_id == 0 && (should_eat_infinitely || p->number_of_meals))
    {
        if ((ft_now() - p->last_meal_time) < p->table->config.time_to_die)
        {
            pthread_mutex_lock(&p->table->death_mutex);
            ft_print_action(p, DIE);
            p->table->dead_philosopher_id = p->id;
//            pthread_mutex_unlock(&p->table->death_mutex);
            break;;
        }
        ft_eat(p);
        ft_print_action(p, SLEEP);
        ft_msleep(p->table->config.time_to_sleep);
        ft_print_action(p, THINK);
    }
    return (NULL);
}
