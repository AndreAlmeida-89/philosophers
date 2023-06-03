//
//  main.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"



int main(int argc, const char **argv)
{
    t_config    config;
    t_table     table;
    
    if (ft_init_config(argc, argv, &config) == FALSE)
        return (1);
    if (ft_init_table(config, &table) == FALSE)
        return (2);
    if (ft_start_threads(table) == FALSE)
        return (3);
    if (ft_wait_threads(table) == FALSE)
        return (4);
    if (ft_destroy(&table) == FALSE)
        return (5);
    return (0);
}
