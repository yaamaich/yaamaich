#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void polymorphism_test() {
	std::cout << "---- polymorphism test ----\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

static void wrong_polymorphism_test() {
	std::cout << "---- wrong polymorphism test ----\n";
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wa->getType() << "\n";
	std::cout << wc->getType() << "\n";

	wa->makeSound();
	wc->makeSound();

	delete wa;
	delete wc;
}

int main() {
	polymorphism_test();
	wrong_polymorphism_test();
	return 0;
}