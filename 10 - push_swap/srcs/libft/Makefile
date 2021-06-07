NAME = libft.a

SRCS = ft_atoi.c			\
	   ft_bzero.c			\
	   ft_calloc.c			\
	   ft_isalpha.c			\
	   ft_isalnum.c			\
	   ft_isdigit.c			\
	   ft_isascii.c			\
	   ft_isprint.c			\
	   ft_itoa.c			\
	   ft_memccpy.c			\
	   ft_memchr.c			\
	   ft_memcpy.c			\
	   ft_memcmp.c			\
	   ft_memmove.c			\
	   ft_memset.c			\
	   ft_putchar_fd.c		\
	   ft_putendl_fd.c		\
	   ft_putnbr_fd.c		\
	   ft_putstr_fd.c		\
	   ft_strchr.c			\
	   ft_strlcat.c			\
	   ft_strlen.c			\
	   ft_strdup.c			\
	   ft_strlcpy.c			\
	   ft_strrchr.c			\
	   ft_strnstr.c			\
	   ft_strncmp.c			\
	   ft_substr.c			\
	   ft_split.c			\
	   ft_strjoin.c			\
	   ft_strmapi.c			\
	   ft_strtrim.c			\
	   ft_strcmp.c			\
	   ft_tolower.c			\
	   ft_toupper.c			\
	   ft_lstnew.c			\
	   ft_lstadd_front.c	\
	   ft_lstsize.c			\
	   ft_lstlast.c			\
	   ft_lstadd_back.c		\
	   ft_lstdelone.c		\
	   ft_lstclear.c		\
	   ft_lstiter.c			\
	   ft_lstmap.c			\
	   get_next_line.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@cd ft_printf && make
	@ar rc $(NAME) $(OBJS) ft_printf/libftprintf.a 

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJS)
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd ft_printf && make fclean

re: fclean all

.PHONY: all clean fclean

