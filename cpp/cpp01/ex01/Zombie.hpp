/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:12:15 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/08 06:30:57 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif