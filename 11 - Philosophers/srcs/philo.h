#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>

typedef struct s_all	t_all;
typedef struct s_philo	t_philo;

struct s_philo {
	int				num;
	int				ate;
	long int		time;
	int				rfork;
	int				lfork;
	t_all			*all;
	pthread_mutex_t	mutex;
	pthread_t		thread;
};

struct s_all {
	int				numphilo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				musteat;
	long int		tstart;
	int				texec;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
};

//		ACTIONS.c
void		*ft_actions(void *param);
int			ft_eat(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			ft_forks(t_philo *philo);
int			ft_unlockforks(t_philo *philo);

//		INIT.c
int			ft_initstruct(t_all *all, char **argv);
int			ft_initphilos(t_all *all);
int			ft_stop(t_philo *philo);
int			ft_stop2(t_philo *philo);

//		LIBFT.c
int			ft_atoi(const char *str);
void		*ft_calloc(size_t num_elements, size_t size);
void		ft_bzero(void *str, size_t x);
int			ft_isdigit(int c);

//		MAIN.c
int			ft_party(t_all *all);
int			ft_endparty(t_all *all);

//		UTILS.c
long int	ft_time(void);
void		ft_usleep(int t);
int			ft_free(t_all *all, int x);
void		ft_printstatus(t_philo *philo, char c);
int			ft_isallnum(char **argv);

#endif
