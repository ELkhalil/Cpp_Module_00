/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:09 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/15 07:46:38 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
public:
    PhoneBook( void );
    ~PhoneBook( void );
    void    add( void );
    void    search( void );
private:
    Contact     _contacts[8];
    int         _contact_count;
    int         _oldest_count;
    void        _display( void );
    std::string _take_input(std::string msg);
    std::string _truncate_str(std::string str);
};

#endif