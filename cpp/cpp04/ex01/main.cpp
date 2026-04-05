#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void array_test() {
	std::cout << "---- array test ----\n";
	const int N = 10;
	Animal* animals[N];

	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < N; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < N; ++i)
		delete animals[i];
}

static void deep_copy_test() {
	std::cout << "---- deep copy test ----\n";

	Dog a;
	a.setIdea(0, "chase ball");
	Dog b(a); // copy ctor

	a.setIdea(0, "sleep");

	std::cout << "a idea0: " << a.getIdea(0) << "\n";
	std::cout << "b idea0: " << b.getIdea(0) << "\n";

	Cat c;
	c.setIdea(1, "eat fish");
	Cat d;
	d = c; // copy assignment
	c.setIdea(1, "ignore humans");

	std::cout << "c idea1: " << c.getIdea(1) << "\n";
	std::cout << "d idea1: " << d.getIdea(1) << "\n";
}

static void delete_as_animal_test() {
	std::cout << "---- delete as Animal* test ----\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
}

int main() {
	array_test();
	deep_copy_test();
	delete_as_animal_test();
	return 0;
}