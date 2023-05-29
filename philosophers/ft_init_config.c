//
//  ft_init_config.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

int ft_is_numeric(int argc, char **argv)
{
    int i;

    i = 0;
    while (++i < argc)
        while (argv[i]++)
            if (*argv[i] < '0' || *argv[i] > '9')
                return (0);
    return (1);
}

int ft_init_config(int argc, const char **argv, t_config *config)
{
    if (argc != 5 && argc != 6 && !ft_is_numeric(argc, argv))
        return (0);
    
    *config = (t_config){
        .number_of_philosophers = atoi(argv[1]),
        .time_to_die = atoi(argv[2]),
        .time_to_eat = atoi(argv[3]),
        .time_to_sleep = atoi(argv[4]),
        .number_of_meals = atoi(argv[5])
    };
    return (1);
}
