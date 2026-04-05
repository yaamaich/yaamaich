NAME = Polymorphism
SRC = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
HPP = Dog.hpp Cat.hpp Brain.hpp Animal.hpp 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o :%.cpp $(HPP)
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean