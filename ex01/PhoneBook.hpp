/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:55:31 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/19 13:29:57 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
    private:
        Contact contacts[8];
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void add_contact(void);
        void display_contacts(void);
        void search_contact(void);
};

#endif