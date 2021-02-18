NAME = minishell

FLAGS = -Wall -Werror -Wextra 

SRCS = src/main.c		\
	   src/profileenv.c	\
	   src/handler.c	\
	   src/exit.c		\
	   src/exec.c		\
	   src/pipes.c		\
	   src/args.c		\
	   src/echo.c		\
	   src/vars.c		\
	   src/export.c		\
	   src/unset.c		\
	   src/cd.c			\
	   src/signals.c	\
	   src/utils.c		\
	   src/utils2.c		\
	   src/utils3.c		\
	   src/utils4.c		\
	   src/redirections.c \
	   src/redirections2.c \
	   src/quotes.c 	\
	   src/utils5.c		\

OBJS = $(SRCS:.s=.o)

UTILS = src/libft/libft.a \
		src/libft/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@cd src/libft && make
	@ar rc $(NAME) $(OBJS) 
	@gcc $(FLAGS) $(OBJS) $(UTILS) -o minishell

%.o: %.c
	@gcc $(FLAGS) $<

clean:
	@rm -f $(O)
	@cd src/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd src/libft && make fclean

re: fclean all

.PHONY: all clean fclean
.PRECIOUS: minishell
