/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:58 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/13 11:31:17 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main( void )
{
    std::string command;
    PhoneBook phoneBook;

    command = "default";
    std::cout << "**** Welcome To The Crappy Phonebook ****" << std::endl;
    while (command != "EXIT")
    {
        std::cout << "Please Enter a Command: {ADD, SEARCH, EXIT} $> ";
        if (!std::getline(std::cin, command) || std::cin.eof())
            std::exit(1);
        if (command == "ADD")
        {
            phoneBook.add();
            command = "default";
        }
        else if (command == "SEARCH")
        {
            phoneBook.search();
            command = "default";
        }
        else if (command == "EXIT")
            return 0;
    }
    return 0;
}