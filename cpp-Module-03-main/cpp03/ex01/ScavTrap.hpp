#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>


class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string n);
        ScavTrap(const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap &other);
        ~ScavTrap();
        void guardGate();
};



#endif