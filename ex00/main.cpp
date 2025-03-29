/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:57:04 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 13:32:44 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage : " << argv[0] << " nb" << std::endl;
        return (0);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}