/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:48:43 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/19 13:27:13 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& num, const std::string& dark)
    : first_name(first), last_name(last), nickname(nick), phone_number(num), darkest_secret(dark){};

std::string Contact::get_first_name() const {return first_name;};
std::string Contact::get_last_name() const {return last_name;};
std::string Contact::get_nickname() const {return nickname;};
std::string Contact::get_phone_number() const {return phone_number;};
std::string Contact::get_darkest_secret() const {return darkest_secret;};
