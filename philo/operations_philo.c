/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:28:47 by darakely          #+#    #+#             */
/*   Updated: 2022/11/03 19:33:18 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died(t_data *_data)
{
	size_t	tm;

	tm = get_time();
	tm -= _data->last_ate_time;
	if (tm >= (size_t)_data->time_of_die)
		return (-1);
	return (0);
}

int	is_died(t_data *_data, char **argv)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < _data->nmb_of_philo)
		{
			if (argv[5] && check_arg_6(_data) == -1)
				return (-1);
			if (check_died(&_data[i]) == -1)
			{
				print(&_data[i], 5);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

void	putting_down_forks(t_data *_data)
{
	pthread_mutex_unlock(_data->mutex_right);
	pthread_mutex_unlock(_data->mutex_left);
}

void	taking_forks(t_data *_data)
{
	pthread_mutex_lock(_data->mutex_left);
	print(_data, 0);
	pthread_mutex_lock(_data->mutex_right);
	print(_data, 0);
}

void	print(t_data *_data, int i)
{
	pthread_mutex_lock(_data->print);
	time_thread(_data);
	if (i == 5)
		printf("%ld:\tPhilosopher %d\t is died ☠️\n", \
				_data->time, _data->ind_struct);
	if (i == 0)
		printf("%ld:\tPhilosopher %d\t has taken a fork 🍴\n", \
				_data->time, _data->ind_struct);
	else if (i == 1)
		printf("%ld:\tPhilosopher %d\t is eating 🍽\n", \
				_data->time, _data->ind_struct);
	else if (i == 2)
		printf("%ld:\tPhilosopher %d\t is sleeping 😴\n", \
				_data->time, _data->ind_struct);
	else if (i == 3)
		printf("%ld:\tPhilosopher %d\t is thinking 🤔\n", \
				_data->time, _data->ind_struct);
	else if (i == 4)
		printf("%ld:\t all ate %d times\n", _data->time,
			_data->nmb_of_each_philo_eat);
	pthread_mutex_unlock(_data->print);
}
