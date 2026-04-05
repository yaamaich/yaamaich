/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:37:32 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/04 13:59:22 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

static std::string  truncate(std::string const &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static std::string  getField(std::string const &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            exit(0);
        }
        if (!input.empty())
            return input;
        std::cout << "Field cannot be empty. Try again." << std::endl;
    }
}

void    PhoneBook::addContact()
{
    int index = oldest % 8;

    contacts[index].setFirstName(getField("First name: "));
    contacts[index].setLastName(getField("Last name: "));
    contacts[index].setNickname(getField("Nickname: "));
    contacts[index].setPhoneNumber(getField("Phone number: "));
    contacts[index].setDarkestSecret(getField("Darkest secret: "));

    oldest++;
    if (count < 8)
        count++;
    std::cout << "Contact saved!" << std::endl;
}

void    PhoneBook::searchContact() const
{
    if (count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index: ";
    std::string line;
    if (!std::getline(std::cin, line))
    {
        std::cout << std::endl;
        return ;
    }

    int idx = -1;
    if (line.length() == 1 && line[0] >= '0' && line[0] <= '7')
        idx = line[0] - '0';

    if (idx < 0 || idx >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }

    std::cout << "First name:     " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last name:      " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname:       " << contacts[idx].getNickname() << std::endl;
    std::cout << "Phone number:   " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}
