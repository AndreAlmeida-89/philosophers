//
//  main.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

int main(int argc, const char **argv)
{
    t_config config;
    
    if (!ft_init_config(argc, argv, &config))
        return (1);
    
    
    return 0;
}
