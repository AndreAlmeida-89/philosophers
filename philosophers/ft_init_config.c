//
//  ft_init_config.c
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#include "philosophers.h"

static int    ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

static int    ft_atoi(const char *str)
{
    int    sign;
    int    nbr;
    int    i;

    sign = 1;
    nbr = 0;
    i = 0;
    while ((str[i] == ' '
            || (str[i] >= '\t' && str[i] <= '\r')))
        i++;
    if ((str[i] == '+' || str[i] == '-'))
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        nbr = (nbr * 10) + (str[i] - '0');
        i++;
    }
    return (nbr * sign);
}

static int ft_is_numeric(int argc, const char **argv)
{
    int i;
    int j;

    i = 0;
    while (++i < argc)
    {
        j = 0;
        while (argv[i][j])
            if (ft_isdigit(argv[i][j++]) == FALSE)
                return (FALSE);
    }
       
    return (TRUE);
}

int ft_init_config(int argc, const char **argv, t_config *config)
{
    if ((argc != 5 && argc != 6)
        || ft_is_numeric(argc, argv) == FALSE)
        return (FALSE);
    config->size = ft_atoi(argv[1]);
    config->time_to_die = ft_atoi(argv[2]);
    config->time_to_eat = ft_atoi(argv[3]);
    config->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        config->number_of_meals = ft_atoi(argv[5]);
    else
        config->number_of_meals = 0;
    return (TRUE);
}
