//
//  philosophers.h
//  philosophers
//
//  Created by Andre Almeida on 29/05/23.
//

#ifndef philosophers_h
#define philosophers_h

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef enum e_bool
{
    FALSE = 0,
    TRUE = 1,
}t_bool;

typedef struct s_config
{
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     number_of_meals;
    int     number_of_philosophers;
} t_config;

typedef struct s_table
{
    pthread_mutex_t *forks;
    time_t          start_time;
    int             dead_philosopher_id;
    t_config        config;
} t_table;

typedef struct s_philo
{
    int             id;
    pthread_t       thread;
    t_table         *table;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    time_t          last_meal_time;
}t_philo;

time_t          ft_now(void);
void            ft_msleep(int milliseconds);
int             ft_init_config(int argc, const char **argv, t_config *config);
pthread_mutex_t *ft_init_forks(int amount);

#endif /* philosophers_h */
