NAME = Megaphone

############ Source ##############

SRC =   ./megaphone.cpp \

############ FLAGS  ##############

FLAG = -Wall -Werror -Wextra -std=c++98 -g

OBJ = $(SRC:.cpp=.o)

CC = c++

############ Compilation ########

%.o: %.cpp
	@c++ $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
