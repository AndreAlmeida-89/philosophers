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
	p->last_meal_time = ft_now();
	ft_print_action(p, EAT);
	ft_wait(p->table->config.time_to_eat, p->table);
	p->number_of_meals--;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

static void		ft_single_philosopher(t_philo *p)
{
	ft_print_action(p, TAKE_FORK);
	usleep(p->table->config.time_to_eat * 1000);
	ft_print_action(p, DIE);
}

void *ft_routine(void *arg)
{
	t_philo *p;
	int     should_eat_infinitely;

	p = (t_philo *)arg;
	should_eat_infinitely = p->number_of_meals == 0;
	if (p->table->config.size == 1)
	{
		ft_single_philosopher(p);
		return (NULL);
	}
	while (should_eat_infinitely || p->number_of_meals)
	{
		pthread_mutex_lock(&p->table->death_mutex);
		if (p->table->dead_philosopher_id)
		{
			pthread_mutex_unlock(&p->table->death_mutex);
			break;
		}
		pthread_mutex_unlock(&p->table->death_mutex);
		if ((ft_now() - p->last_meal_time) >= p->table->config.time_to_die)
		{
			pthread_mutex_lock(&p->table->death_mutex);
			p->table->dead_philosopher_id = p->id;
			pthread_mutex_unlock(&p->table->death_mutex);
			usleep(7000);
			ft_print_action(p, DIE);
			break;
		}
		printf("last meal diff: %ld\n", ft_now() - p->last_meal_time);
		ft_eat(p);
		ft_print_action(p, SLEEP);
		if (ft_wait(p->table->config.time_to_sleep, p->table) == FALSE)
			break;
		ft_print_action(p, THINK);
	}
	return (NULL);
}
