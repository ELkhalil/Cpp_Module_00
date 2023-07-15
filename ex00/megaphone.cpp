/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:13:25 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/11 16:06:22 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
    char    c;

    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
        {
            for(int j = 0; j < (int)strlen(av[i]); j++)
            {
                c = av[i][j];
                if (isalpha(c))
                    c = toupper(c);
                std::cout << c;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}