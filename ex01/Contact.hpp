/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:40 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/13 17:23:14 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
 
class Contact {
public:
    Contact( void );
    ~Contact( void );
    Contact(std::string& first, std::string& last, std::string& nick, std::string& phone, std::string& dark);
    std::string    getFirstName() const;
    std::string    getLastName() const;
    std::string    getNickName() const;
    std::string    getPhoneNumber() const;
    std::string    getDarkestSecret() const;
private:
    std::string     _firstName;
    std::string     _lastName;
    std::string     _nickName;
    std::string     _phoneNumber;
    std::string     _darkestSecret;
};

#endif