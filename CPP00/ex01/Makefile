NAME = PhoneBook

############ Source ##############

SRC =   ./main.cpp		\
		./PhoneBook.cpp \
		./Contact.cpp

############ FLAGS  ##############

FLAG = -Wall -Werror -Wextra -std=c++98 -g

OBJ = $(SRC:.cpp=.o)

CC = c++

############ Compilation ########

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
