/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:14:29 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/08 06:24:49 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the string variable:       " << &str << std::endl;
    std::cout << "The memory address held by stringPTR:            " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF:            " << &stringREF << std::endl;

    std::cout << "The value of the string variable:                " << str << std::endl;
    std::cout << "The value pointed to by stringPTR:               " << *stringPTR << std::endl;
    std::cout << "he value pointed to by stringREF:                " << stringREF << std::endl;

    return 0;
}