#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    Name = "None";
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(std::string n)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    Name = n;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
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

std::string ClapTrap::get_name() const
{
    return Name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Name = other.get_name();
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_points <= 0)
    {
        std::cout << "ClapTrap " << Name << " is dead and can't attack!" << std::endl;
        return;
    }
    if(energy_points <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << Name << " attacks " << target 
          << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= (unsigned int)hit_points)
    {
        std::cout << "ClapTrap " << Name << " takes " << hit_points << " points of damage and dies!" << std::endl;
        hit_points = 0;
    }
    else
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points <= 0)
    {
        std::cout << "ClapTrap " << Name << " is dead and can't repair!" << std::endl;
        return;
    }
    if(energy_points <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy left!" << std::endl;
        return;
    }
    hit_points = hit_points + amount;
    energy_points--;
    std::cout << "ClapTrap " << Name << " is repaired by " << amount << " points!" << std::endl;
}
