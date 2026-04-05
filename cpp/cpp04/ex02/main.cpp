#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;
	return 0;
}