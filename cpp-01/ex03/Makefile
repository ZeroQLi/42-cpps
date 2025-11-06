NAME = zombie03

COMP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = src/main.cpp \
src/HumanA.cpp src/HumanB.cpp src/Weapon.cpp
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