NAME = get_next_line.a

all:
	@cd ../libft && make
	@gcc -Wextra -Werror -Wall -c get_next_line.c get_next_line_utils.c
	@ar rc $(NAME) get_next_line.o
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all
