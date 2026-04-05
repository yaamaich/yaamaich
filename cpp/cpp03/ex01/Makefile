NAME = ScavTrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
HPP = ClapTrap.hpp ScavTrap.hpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(OBJ) $(HPP) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) 

re: fclean all

.PHONY: clean