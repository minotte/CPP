NAME = RPN


############ Source ##############

SRC =   ./main.cpp					\
		./RPN.cpp
				

############ FLAGS  ##############

FLAG = -Wall -Werror -Wextra -std=c++98 -g 

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
