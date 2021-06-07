# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:10:22 by nasimon-          #+#    #+#              #
#    Updated: 2021/05/04 16:11:59 by nayran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c							\
	   casos_flags/ft_caso_c.c				\
	   casos_flags/ft_caso_d.c				\
	   casos_flags/ft_caso_p.c				\
	   casos_flags/ft_caso_pct.c			\
	   casos_flags/ft_caso_s.c				\
	   casos_flags/ft_caso_x.c				\
	   casos_flags/ft_caso_u.c				\
	   casos_flags/ft_flags_compr.c			\
	   complementos/ft_itoa.c				\
	   complementos/ft_putchar.c			\
	   complementos/ft_putstr.c				\
	   complementos/ft_strchr.c				\
	   complementos/ft_strlen.c				\
	   complementos/ft_uitoa_base.c			\
	   complementos/ft_uitoa.c				\

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
.PRECIOUS: libftprintf.a
