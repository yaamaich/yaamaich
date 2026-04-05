#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	 brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
	*this = other;
}
Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructore called" << std::endl;
	delete brain;
}
void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea) {
	brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const {
	return brain->getIdea(idx);
}