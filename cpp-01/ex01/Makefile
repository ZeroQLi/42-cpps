NAME = zombie01

COMP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = src/main.cpp \
	src/Zombie.cpp \
	src/zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re