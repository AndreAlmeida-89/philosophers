//
//  ft_print_action.c
//  philosophers
//
//  Created by Andre Almeida on 02/06/23.
//

#include "philosophers.h"

static const char *ft_get_action_str(t_action action)
{
    if (action == EAT)
        return ("is eating");
    else if (action == SLEEP)
        return ("is sleeping");
    else if (action == THINK)
        return ("is thinking");
    else if (action == DIE)
        return ("died");
    else if (action == TAKE_FORK)
        return ("has taken fork");
    else
        return (NULL);
}

int ft_print_action(t_philo *p, t_action action)
{
    if (action != DIE && p->table->dead_philosopher_id)
        return (FALSE);
    printf("%ld\t\t%d\t%s\n",
           ft_now() - p->table->start_time,
           p->id,
           ft_get_action_str(action));
    return (TRUE);
}
