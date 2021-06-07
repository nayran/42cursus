NAME = cub3D

SRCS = others/main.c	\
       others/lecub.c	\
       others/handlecases.c \
       others/handlemap.c \
       others/utils2.c	\
       others/utils.c	\
       others/raycast.c	\
       others/draws.c	\
       others/move.c	\
       others/sprites.c	\
       others/bmp.c

OBJ = main.o	\
	   lecub.o	\
	   handlecases.o	\
	   handlemap.o	\
	   utils2.o	\
	   utils.o	\
	   raycast.o	\
	   draws.o	\
	   move.o	\
	   sprites.o	\
	   bmp.o

FLAG = -Wall -Wextra -Werror

MLXFLAG = -lmlx -framework OpenGL -framework Appkit 

all: $(NAME)

$(NAME):
	@make -C utils/libft
	@make -C utils/minilibx
	@make -C utils/ft_printf
	@gcc $(FLAGS) -c $(SRCS)
	@mv utils/minilibx/libmlx.a .
	@mv utils/libft/libft.a .
	@mv utils/ft_printf/libftprintf.a .
	@gcc $(FLAGS) $(SRCS) -I. -L. -lft libft.a libmlx.a libftprintf.a $(MLXFLAG) -o $(NAME)

linux:
	@make -C utils/libft/ linux
	@make -C utils/ft_printf/
	@gcc $(FLAG) $(SRCS) utils/minilibx-linux/libmlx.a utils/libft/libft.a utils/ft_printf/libftprintf.a -lm -lbsd -lmlx -lXext -lX11 

clean:
	@make -C utils/minilibx clean
	@make -C utils/libft clean
	@make -C utils/ft_printf clean
	@rm -rf $(OBJ) libft.a libmlx.a libftprintf.a a.out

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
