//
//  ft_msleep.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

void    ft_msleep(int milliseconds)
{
    usleep(milliseconds * 1000);
}
