/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:38 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/15 07:46:35 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

PhoneBook::PhoneBook( void ) {
    this->_contact_count = 0;
}

PhoneBook::~PhoneBook( void ) {}

void    PhoneBook::add( void ) {
    std::string name, last, nick, phone, dark;

    name = this->_take_input("First Name :");
    last = this->_take_input("Last Name: ");
    nick = this->_take_input("Nick Name: ");
    phone = this->_take_input("Phone Number: ");
    dark = this->_take_input("Dark Secret: ");
    Contact tmp_contact(name, last, nick, phone, dark);
    int i = 0;
    while (i < 8)
    {
        if (!_contacts[i].getFirstName().empty())
            i++;
        else
            break;
    }
    if (i < 8)
    {
        _contacts[i] = tmp_contact;
        this->_contact_count++;
    }
    else
    {
        
        _contacts[0] = tmp_contact;
        this->_contact_count = 8;
    }
}

void    PhoneBook::_display( void ) {
    std::cout << std::setw(10)  << "index" << " | " <<
                 std::setw(10)  << "first name" << " | " <<
                 std::setw(10)  << "last name" << " | " <<
                 std::setw(10)  << "nickname";
    std::cout << std::endl;
    for(int i=0; i < this->_contact_count; i++)
    {
        std::cout << std::setw(10)  << i + 1 << " | " <<
                     std::setw(10)  << this->_truncate_str(_contacts[i].getFirstName()) << " | " <<
                     std::setw(10)  << this->_truncate_str(_contacts[i].getLastName()) << " | " <<
                     std::setw(10)  << this->_truncate_str(_contacts[i].getNickName());
        std::cout << std::endl;
    }
}

void    PhoneBook::search( void ) {
    std::string line;
    int selected_contact;

    if (!this->_contact_count)
    {
        std::cout << "! the list of contacts is empty !" << std::endl;
        std::cout << "*** try to ADD a new contact ***" << std::endl;
        return ;
    }
    this->_display();
    std::cout << "Enter the contact index $> ";
    std::getline(std::cin, line);
    if (std::cin.eof())
       std::exit(1);
    for (int i = 0; i < (int)line.length(); i++)
    {
        if (!std::isdigit(line[i]))
        {
            std::cout << "Invalid Input" << std::endl;
            return ;
        }
    }
    selected_contact = std::stoi(line);
    if (selected_contact < 1 || selected_contact > 8 || selected_contact > _contact_count)
        std::cout << "Invalid Index" << std::endl;
    else
    {
        std::cout << "First Name: " << _contacts[selected_contact - 1].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[selected_contact - 1].getLastName() << std::endl;
        std::cout << "Nick Name: " << _contacts[selected_contact - 1].getNickName() << std::endl;
        std::cout << "Phone Number: " << _contacts[selected_contact - 1].getPhoneNumber() << std::endl;
        std::cout << "Dark Secret: " << _contacts[selected_contact - 1].getDarkestSecret() << std::endl;
    }
}

std::string    PhoneBook::_take_input(std::string msg)
{
    std::string input;
    bool    flag;

    flag = true;
    while (flag)
    {
        std::cout << msg;
        std::getline(std::cin, input);
        if (std::cin.eof())
            std::exit(1);
        std::size_t found = input.find_first_not_of(" \t\n\r\f\v");
        if (input.empty() || found == std::string::npos)
            continue;
        else
            flag = false;
    }
    int f_index = input.find_first_not_of(" \t\n\r\f\v");
    int l_index = input.find_last_not_of(" \t\n\r\f\v");
    return (input.substr(f_index, l_index));
}

std::string PhoneBook::_truncate_str(std::string str)
{
    std::string truncated_str;

    truncated_str = (str.length() >= 10) ? str.substr(0, 9) + "." : str;
    return (truncated_str);
}
