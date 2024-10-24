NAME = ex03


############ Source ##############

SRC =   ./main.cpp					\
		./Character.cpp				\
		./Cure.cpp					\
		./Ice.cpp					\
		./AMateria.cpp				\
		./MateriaSource.cpp			\
		

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
