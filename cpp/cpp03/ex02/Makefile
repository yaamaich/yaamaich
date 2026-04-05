NAME = FragTrap
SRC = main.cpp FragTrap.cpp ClapTrap.cpp
HPP = FragTrap.hpp ClapTrap.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HPP)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean