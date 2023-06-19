/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:02:58 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/11 14:55:13 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int main(int ac, char **av) 
{
	char	c;

	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; j < (int)strlen(av[i]); ++j) {
			c = av[i][j];
			if (islower(c))
				c = toupper(c);
			std::cout << c;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
