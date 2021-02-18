NAME = libasm.a

FLAGS = -Wall -Werror -Wextra

SRCS = src/ft_strlen.s	\
	   src/ft_strcpy.s	\
	   src/ft_strcmp.s	\
	   src/ft_write.s	\
	   src/ft_read.s	\
	   src/ft_strdup.s

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(NAME) src/main.c -o asm

%.o: %.s
	nasm -fmacho64 $<

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) tests asm

re: fclean all

.PHONY: all clean fclean re
