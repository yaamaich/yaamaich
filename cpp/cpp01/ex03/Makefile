NAME	= humans

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC    = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY : all clean fclean re
