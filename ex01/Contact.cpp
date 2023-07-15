/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:43 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/13 17:23:36 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {}
Contact::~Contact( void ) {}

Contact::Contact(std::string& first, std::string& last, std::string& nick, std::string& phone, std::string& dark)
    : _firstName(first), _lastName(last), _nickName(nick), _phoneNumber(phone), _darkestSecret(dark) {}

std::string    Contact::getFirstName() const { return _firstName;};
std::string    Contact::getLastName() const { return _lastName;};
std::string    Contact::getNickName() const { return _nickName;};
std::string    Contact::getPhoneNumber() const { return _phoneNumber;};
std::string    Contact::getDarkestSecret() const { return _darkestSecret;};
