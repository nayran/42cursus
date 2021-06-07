PUSH_SWAP = push_swap
CHECKER = checker

SRCP = srcs/push_swap.c	

SRCC = srcs/checker_bonus.c			\

SRCS = srcs/utils/args.c			\
	   srcs/utils/chunks.c			\
	   srcs/utils/chunkutils.c		\
	   srcs/utils/commands.c		\
	   srcs/utils/commands2.c		\
	   srcs/utils/insertion.c		\
	   srcs/utils/nodeutils.c		\
	   srcs/utils/nodeutils2.c		\
	   srcs/utils/position.c		\
	   srcs/utils/sort.c			\
	   srcs/utils/sortutils.c		\
	   srcs/utils/stack.c			\
	   srcs/utils/stackutils.c		\
	   srcs/utils/utils.c


OBJP = $(SRCP:.c=.o)
OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra
UTILS = srcs/libft/libft.a 			\
		srcs/libft/ft_printf/libftprintf.a

all: $(PUSH_SWAP) 

bonus: $(CHECKER) 
	
$(PUSH_SWAP): $(OBJS) $(OBJP) 
	@cd srcs/libft && make
	@ar rc $(PUSH_SWAP) $(OBJS) $(OBJP)
	@gcc $(FLAGS) $(OBJS) $(OBJP) $(UTILS) -o push_swap

$(CHECKER): $(OBJS) $(OBJC)
	@cd srcs/libft && make
	@ar rc $(CHECKER) $(OBJS) $(OBJC)
	@gcc $(FLAGS) $(OBJS) $(OBJC) $(UTILS)  -o checker

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJC) $(OBJP)
	@cd srcs/libft && make clean

fclean: clean
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@cd srcs/libft && make fclean

re: fclean all

.PHONY: all clean fclean
.PRECIOUS: checker push_swap
