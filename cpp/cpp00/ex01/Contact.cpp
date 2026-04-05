/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:16:00 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/04 14:00:05 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string const &val)	{ firstName = val; }
void	Contact::setLastName(std::string const &val)	{ lastName = val; }
void	Contact::setNickname(std::string const &val)	{ nickname = val; }
void	Contact::setPhoneNumber(std::string const &val)	{ phoneNumber = val; }
void	Contact::setDarkestSecret(std::string const &val){ darkestSecret = val; }

std::string Contact::getFirstName() const		{ return firstName; }
std::string Contact::getLastName() const		{ return lastName; }
std::string Contact::getNickname() const		{ return nickname; }
std::string Contact::getPhoneNumber() const		{ return phoneNumber; }
std::string Contact::getDarkestSecret() const	{ return darkestSecret; }
