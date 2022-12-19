/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:50:00 by darakely          #+#    #+#             */
/*   Updated: 2022/11/03 19:33:26 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_main(void *data)
{
	t_data	*_data;

	_data = data;
	_data->last_ate_time = get_time();
	if (_data->ind_struct % 2 == 0)
		usleep(100);
	while (1)
	{
		taking_forks(_data);
		_data->count_eat++;
		print(_data, 1);
		_timer(_data->time_of_eat);
		_data->last_ate_time = get_time();
		putting_down_forks(_data);
		print(_data, 2);
		_timer(_data->time_of_sleep);
		print(_data, 3);
	}
	return (0);
}

t_data	*init_arguments(char **argv)
{
	int		i;
	t_data	*_data;

	i = 0;
	_data = NULL;
	_data = malloc(sizeof(t_data) * ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		_data[i].nmb_of_philo = ft_atoi(argv[1]);
		_data[i].time_of_die = ft_atoi(argv[2]);
		_data[i].time_of_eat = ft_atoi(argv[3]);
		_data[i].time_of_sleep = ft_atoi(argv[4]);
		_data[i].ind_struct = i + 1;
		_data[i].count_eat = 0;
		_data[i].died = 0;
		if (argv[5])
			_data[i].nmb_of_each_philo_eat = ft_atoi(argv[5]);
		else
			_data[i].nmb_of_each_philo_eat = -1;
		i++;
	}
	return (_data);
}

int	check_nmb(t_data *_data, char **argv)
{
	if (_data->nmb_of_philo < 1 || _data->time_of_die < 1
		|| _data->time_of_eat < 1 || _data->time_of_sleep < 1
		|| (argv[5] && _data->nmb_of_each_philo_eat < 1))
	{
		printf("Error: wrong arguments\n");
		return (-1);
	}
	return (0);
}

int	check_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (ft_atoi(argv[i]) < 1)
		return (-1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				if (!(argv[i][j] == '-' || argv[i][j] == '+'))
				{
					printf("Error: character in arguments\n");
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*_data;

	if (argc == 5 || argc == 6)
	{
		if (check_arguments(argv) == -1)
			return (-1);
		_data = init_arguments(argv);
		if (check_nmb(_data, argv) == -1)
			return (-1);
		if (init_mutex(_data) == -1)
		{
			free_all(_data);
			return (-1);
		}
		if (is_died(_data, argv) == -1)
		{
			free_all(_data);
			return (-1);
		}
	}
	else
		printf("Error: more or less arguments\n");
	return (0);
}
