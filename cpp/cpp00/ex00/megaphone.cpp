/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:45:40 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/05 06:56:22 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void ft_uppercase(char *str)
{
	for (int i = 0; str[i];i++)
		std::cout << (char)toupper(str[i]);
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; av[i]; i++)
	{
		ft_uppercase(av[i]);
	}
	std::cout << std::endl;
}
