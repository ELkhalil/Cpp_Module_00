/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:58:51 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/19 13:12:48 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;

    std::string command;
    while (command != "EXIT")
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD")
        {
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            phonebook.display_contacts();
            phonebook.search_contact();
        }
    }
    return 0;
}
