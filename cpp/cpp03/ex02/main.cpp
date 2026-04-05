#include "FragTrap.hpp"

int main()
{
    FragTrap hero("Hero");

    hero.attack("Monster");
    hero.takeDamage(10);
    hero.beRepaired(15);
    hero.highFivesGuys();
}