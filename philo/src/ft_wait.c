/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:38:22 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/08 14:14:06 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_wait(int milliseconds)
{
	time_t	start;

	start = ft_now();
	while (ft_now() < start + milliseconds)
		usleep(100);
	return (TRUE);
}
