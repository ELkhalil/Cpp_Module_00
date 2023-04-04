/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:48:34 by aelkhali          #+#    #+#             */
/*   Updated: 2023/04/04 10:51:07 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void) {
    
    std::cout << "Constructor Called" << std::endl;
    return ;
}

PhoneBook::~PhoneBook (void) {
    
    std::cout << "Destructor Called" << std::endl;
    return ;
}
