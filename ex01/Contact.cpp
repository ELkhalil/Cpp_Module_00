/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:48:43 by aelkhali          #+#    #+#             */
/*   Updated: 2023/04/04 10:50:40 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact (void) {
    
    std::cout << "Constructor Called" << std::endl;
    return ;
}

Contact::~Contact (void) {
    
    std::cout << "Destructor Called" << std::endl;
    return ;
}
