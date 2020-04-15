NAME = cub3d.a

SRC = ./others/*.c	\
	  ./utils/get_next_line/get_next_line.a	\
	  ./utils/libft/libft.a

all:
	cd utils/get_next_line && make
	gcc cub3D.c $(SRC)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all
