#include "ScavTrap.hpp"

int main()
{
    ScavTrap guardian("mehdi");

    guardian.attack("Enemy");
    guardian.takeDamage(30);
    guardian.beRepaired(10);
    guardian.guardGate();
}
