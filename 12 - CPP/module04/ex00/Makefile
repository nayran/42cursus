NAME = animal

SRCS = main.cpp				\
	   AnimalClass.cpp		\
	   DogClass.cpp			\
	   CatClass.cpp			\
	   WrongAnimalClass.cpp	\
	   WrongCatClass.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@clang++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
