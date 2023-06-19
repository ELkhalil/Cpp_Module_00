/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:48:34 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/19 13:27:46 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void) {}

PhoneBook::~PhoneBook (void) {}

void    PhoneBook::add_contact(void)
{
    std::string first, last, nick, number, dark;
    
    std::cout << "Enter the first name: ";
    std::cin >> first;
    std::cout << "Enter the last name: ";
    std::cin >> last;
    std::cout << "Enter the nickname: ";
    std::cin >> nick;
    std::cout << "Enter the Phone Number: ";
    std::cin >> number;
    std::cout << "Enter the Dark Secret: ";
    std::cin >> dark;

    Contact new_contact(first, last, nick, number, dark);
    int index = 0;
    while (index < 8 && !contacts[index].get_first_name().empty())
        index++;
    if (index < 8)
    {
        contacts[index] = new_contact;
        std::cout << "Contact added successfully!" << std::endl;
    }
    else
    {
        std::cout << "Phone book is full. The oldest contact will be replaced." << std::endl;
        contacts[0] = new_contact;
    }
}

void    PhoneBook::display_contacts(void)
{
    std::cout << std::setw(10) << "Index" << std::setw(10) << "First Name" << std::setw(10) << "Last Name" << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << i;
        std::cout << std::setw(10) << (contacts[i].get_first_name().length() > 10 ? contacts[i].get_first_name().substr(0, 9) + "." : contacts[i].get_first_name());
        std::cout << std::setw(10) << (contacts[i].get_last_name().length() > 10 ? contacts[i].get_last_name().substr(0, 9) + "." : contacts[i].get_last_name());
        std::cout << std::setw(10) << (contacts[i].get_nickname().length() > 10 ? contacts[i].get_nickname().substr(0, 9) + "." : contacts[i].get_nickname());
        std::cout << std::endl;
    }
}

void    PhoneBook::search_contact(void)
{
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;
    if (index >= 0 && index < 8 && !contacts[index].get_first_name().empty())
    {
        std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
        std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
        std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
    }
    else
        std::cout << "Invalid index or contact does not exist." << std::endl;
}
