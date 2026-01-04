NAME = abstract

COMP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = src/Animal.cpp \
	src/Cat.cpp \
	src/Dog.cpp \
	src/WrongAnimal.cpp \
	src/WrongCat.cpp \
	src/Brain.cpp \
	src/main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re