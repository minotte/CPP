NAME = ex01


############ Source ##############

SRC =   ./main.cpp				\
		./Dog.cpp				\
		./Cat.cpp				\
		./Animal.cpp			\
		./WrongCat.cpp				\
		./WrongAnimal.cpp			\
		./Brain.cpp

############ FLAGS  ##############

FLAG = -Wall -Werror=extra -Wextra -std=c++98 -g -D_GLIBCXX_DEBUG

OBJ = $(SRC:.cpp=.o)

CXX = c++

############ Compilation ########

%.o: %.cpp
	$(CXX) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
