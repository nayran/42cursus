NAME = cub3d.a

SRC = ./others/*.c	\
	  ./others/get_next_line/get_next_line.a	\
	  ./others/libft/libft.a

all:
	cd others/get_next_line && make
	gcc cub3d.c $(SRC)
	./a.out map/map.cub | cat -e
	rm a.out

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all
