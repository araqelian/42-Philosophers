/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:07:15 by darakely          #+#    #+#             */
/*   Updated: 2022/10/28 01:39:33 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_thread(t_data *_data)
{
	struct timeval	tm;

	gettimeofday(&tm, 0);
	tm.tv_sec *= 1000;
	tm.tv_usec /= 1000;
	_data->time = (tm.tv_sec + tm.tv_usec) - _data->start_time;
	return (_data->time);
}

void	_timer(size_t tm)
{
	size_t	time;
	size_t	n_time;

	time = get_time();
	n_time = get_time();
	while ((n_time - time) < tm)
	{
		n_time = get_time();
		usleep(10);
	}
}

size_t	get_time(void)
{
	struct timeval	tm;
	size_t			time;

	gettimeofday(&tm, 0);
	time = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (time);
}

int	get_thread(t_data *_data)
{
	int	i;

	i = 0;
	while (i < _data->nmb_of_philo)
	{
		_data[i].start_time = get_time();
		_data[i].print = _data[0].print;
		if ((pthread_create(&_data[i].th, 0, &philo_main, &_data[i])) == -1)
		{
			printf("Error: pthread_create function not working\n");
			return (-1);
		}
		pthread_detach(_data[i].th);
		i++;
	}
	usleep(10);
	return (0);
}

int	init_mutex(t_data *_data)
{
	int	i;

	i = 0;
	_data->mutex = malloc(sizeof(pthread_mutex_t) * _data->nmb_of_philo);
	_data->print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(_data->print, 0);
	while (i < _data[0].nmb_of_philo)
	{
		pthread_mutex_init(&_data->mutex[i], 0);
		i++;
	}
	i = 0;
	while (i < _data[0].nmb_of_philo)
	{
		if ((i + 1) == _data[0].nmb_of_philo)
			_data[i].mutex_left = &_data->mutex[0];
		else
			_data[i].mutex_left = &_data->mutex[i + 1];
		_data[i].mutex_right = &_data->mutex[i];
		i++;
	}
	if (get_thread(_data) == -1)
		return (-1);
	return (0);
}
