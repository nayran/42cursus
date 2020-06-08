NAME = cub3d.a

SRC = ./others/*.c	\
	  ./others/get_next_line/get_next_line.a	\
	  ./others/libft/libft.a

MLX = -I .others/minilibx -L ./others/minilibx/ -lmlx -framework OpenGL -framework AppKit

MEM = -fsanitize=address 

all:
	@cd others/get_next_line && make
	@cd others/minilibx && make
	@gcc -Wall -Wextra -Werror $(MEM) $(MLX) cub3d.c $(SRC)
	@./a.out map/map.cub
	@rm a.out

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all
