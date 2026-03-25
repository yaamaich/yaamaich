#include "ClapTrap.hpp"

int main()
{
    ClapTrap warrior("Mehdi");
    
    warrior.attack("Zombie");
    warrior.takeDamage(9);
    warrior.beRepaired(10);
}
