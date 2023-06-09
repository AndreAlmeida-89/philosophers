/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:50:43 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/09 01:03:10 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef struct s_config
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	int	size;
}	t_config;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	time_t			start_time;
	t_bool			has_dead_philo;
	t_config		config;
	struct s_philo	*philos;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				number_of_meals;
	pthread_t		thread;
	t_table			*table;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	time_t			last_meal_time;
}	t_philo;

typedef enum e_action
{
	EAT,
	TAKE_FORK,
	SLEEP,
	THINK,
	DIE,
}	t_action;

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
time_t			ft_now(void);
void			ft_msleep(int milliseconds);
int				ft_init_config(int argc, const char **argv, t_config *config);
pthread_mutex_t	*ft_init_forks(int amount);
int				ft_init_philosophers(t_table *table);
int				ft_start_threads(t_table table);
int				ft_init_table(t_config config, t_table *table);
void			*ft_routine(void *arg);
int				ft_wait_threads(t_table table);
void			ft_destroy(t_table *table);
int				ft_print_action(t_philo *p, t_action action);
int				ft_wait(int milliseconds, t_table *t);
void			*ft_monitor(void *arg);

#endif
