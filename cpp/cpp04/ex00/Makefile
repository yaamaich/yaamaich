NAME = Polymorphism
SRC = main.cpp Dog.cpp Cat.cpp WrongCat.cpp Animal.cpp WrongAnimal.cpp
HPP = Dog.hpp Cat.hpp WrongCat.hpp Animal.hpp WrongAnimal.hpp
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