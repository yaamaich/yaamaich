#include "FragTrap.hpp"

int main()
{
    FragTrap hero("F1");

    hero.attack("Monster");
    hero.takeDamage(30);
    hero.beRepaired(15);
    hero.highFivesGuys();
}