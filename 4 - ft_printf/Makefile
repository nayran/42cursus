# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:10:22 by nasimon-          #+#    #+#              #
#    Updated: 2020/02/19 19:25:52 by nasimon-         ###   ########.fr        #
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

OBJECTS = ft_printf.o				\
		  ft_caso_c.o				\
		  ft_caso_d.o				\
		  ft_caso_p.o				\
		  ft_caso_pct.o				\
		  ft_caso_s.o				\
		  ft_caso_x.o				\
		  ft_caso_u.o				\
		  ft_flags_compr.o			\
		  ft_itoa.o					\
		  ft_putchar.o				\
		  ft_putstr.o				\
		  ft_strchr.o				\
		  ft_strlen.o				\
		  ft_uitoa_base.o			\
		  ft_uitoa.o				\

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS) : $(SRCS) $(LIB)
	@gcc -Wextra -Werror -Wall -c -g -I $(LIB) $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
