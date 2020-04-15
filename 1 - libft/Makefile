NAME = libft.a

C = ft_atoi.c		\
	ft_calloc.c		\
	ft_isalpha.c	\
	ft_bzero.c		\
	ft_isalnum.c	\
	ft_isdigit.c	\
	ft_isascii.c	\
	ft_isprint.c	\
	ft_memccpy.c	\
	ft_memchr.c		\
	ft_memcpy.c		\
	ft_memcmp.c		\
	ft_memmove.c	\
	ft_memset.c		\
	ft_strchr.c		\
	ft_strlcat.c	\
	ft_strlen.c		\
	ft_strdup.c		\
	ft_strlcpy.c	\
	ft_strrchr.c	\
	ft_tolower.c	\
	ft_toupper.c	\
	ft_strnstr.c	\
	ft_strncmp.c	\
	ft_substr.c		\
	ft_itoa.c		\
	ft_putchar_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
	ft_split.c		\
	ft_strjoin.c	\
	ft_strmapi.c	\
	ft_strtrim.c

O = ft_atoi.o		\
	ft_calloc.o		\
	ft_isalpha.o	\
	ft_bzero.o		\
	ft_isalnum.o	\
	ft_isdigit.o	\
	ft_isascii.o	\
	ft_isprint.o	\
	ft_memccpy.o	\
	ft_memchr.o		\
	ft_memcpy.o		\
	ft_memcmp.o		\
	ft_memmove.o	\
	ft_memset.o		\
	ft_strchr.o		\
	ft_strlcat.o	\
	ft_strlen.o		\
	ft_strdup.o		\
	ft_strlcpy.o	\
	ft_strrchr.o	\
	ft_tolower.o	\
	ft_toupper.o	\
	ft_strnstr.o	\
	ft_strncmp.o	\
	ft_substr.o		\
	ft_itoa.o		\
	ft_putchar_fd.o	\
	ft_putendl_fd.o	\
	ft_putnbr_fd.o	\
	ft_putstr_fd.o	\
	ft_split.o		\
	ft_strjoin.o	\
	ft_strmapi.o	\
	ft_strtrim.o

H = libft.h

FLAG = -Wall 		\
	   -Wextra 		\
	   -Werror

CB = ft_lstnew.c		\
	 ft_lstadd_front.c	\
	 ft_lstsize.c		\
	 ft_lstlast.c		\
	 ft_lstadd_back.c	\
	 ft_lstdelone.c		\
	 ft_lstclear.c		\
	 ft_lstiter.c		\
	 ft_lstmap.c

OB = ft_lstnew.o		\
	 ft_lstadd_front.o	\
	 ft_lstsize.o		\
	 ft_lstlast.o		\
	 ft_lstadd_back.o	\
	 ft_lstdelone.o		\
	 ft_lstclear.o		\
	 ft_lstiter.o		\
	 ft_lstmap.o

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(C) -I $(H)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

bonus:
	gcc -c $(FLAG) $(C) $(CB) -I $(H)
	ar rc $(NAME) $(O) $(OB)
	ranlib $(NAME)

clean:
	rm -f $(O) $(OB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

