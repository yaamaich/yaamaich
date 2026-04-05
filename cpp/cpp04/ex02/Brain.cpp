#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called" << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea)
{
	if (idx < 0 || idx >= 100)
		return;
	ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		return "";
	return ideas[idx];
}