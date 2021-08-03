PHILO = philo

SRCS = srcs/main.c			\
	   srcs/actions.c		\
	   srcs/init.c			\
	   srcs/libft.c			\
	   srcs/utils.c			\

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -fsanitize=address

all: $(PHILO)

$(PHILO): $(OBJS)
	@clang $(FLAGS) $(OBJS) -o philo

%.o: %.c
	@clang -c $(FLAGS) $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(PHILO)

re: fclean all

.PHONY: all clean fclean
.PRECIOUS: philo
