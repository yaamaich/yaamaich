#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	Name = "Default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	Name = n;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	 std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " destroyed" << std::endl;
}
std::string ClapTrap::_getName() const
{
	return Name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->Name = other._getName();
		this->hitPoints = other.hitPoints;
		this->energyPoints  = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		 std::cout << "ClapTrap " << Name << " is dead and can't attack!" << std::endl;
		 return;
	}
	if(energyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << Name << " attacks " << target 
          << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= (unsigned int)hitPoints)
    {
        std::cout << "ClapTrap " << Name << " takes " << hitPoints << " points of damage and dies!" << std::endl;
        hitPoints = 0;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " is dead and can't repair!" << std::endl;
        return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " has no energy left!" << std::endl;
        return;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << "ClapTrap " << Name << " is repaired by " << amount << " points!" << std::endl;
}