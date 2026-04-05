#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
	*this = other;
}
Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructore called" << std::endl;
	delete brain;
}
void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea) {
	brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const {
	return brain->getIdea(idx);
}