#include "ClapTrap.hpp"

int main()
{
    ClapTrap warrior("Yahya");
    
    warrior.attack("Zombie");
    warrior.takeDamage(100);
    warrior.beRepaired(10);
}