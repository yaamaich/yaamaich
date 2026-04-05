#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constracture called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy Assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}
std::string Animal::getType() const
{
	return type;
}
void Animal::makeSound(void) const
{
	std::cout << "Animal made a sound" << std::endl;
}
