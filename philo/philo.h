/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:38:13 by darakely          #+#    #+#             */
/*   Updated: 2022/10/13 18:05:39 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nmb_of_philo;
	int				time_of_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				nmb_of_each_philo_eat;
	int				ind_struct;
	int				count_eat;
	int				died;
	size_t			last_ate_time;
	long int		time;
	unsigned long	start_time;
	pthread_t		th;
	pthread_mutex_t	*print;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
}				t_data;

//main
int				check_arguments(char **argv);
int				check_nmb(t_data *_data, char **argv);
void			ft_usleep(void);
void			*philo_main(void *data);

//philo
int				init_mutex(t_data *_data);
int				get_thread(t_data *_data);
size_t			get_time(void);
void			_timer(size_t tm);
size_t			time_thread(t_data *_data);

//operations_philo
void			taking_forks(t_data *_data);
void			putting_down_forks(t_data *_data);
void			print(t_data *_data, int i);
int				is_died(t_data *_data, char **argv);
int				check_died(t_data *_data);

//utils
long int		ft_atoi(char *str);
int				check_arg_6(t_data *_data);
void			free_all(t_data *_data);

#endif
