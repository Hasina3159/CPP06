/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:40:54 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/04/01 16:10:46 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>

void print_value(const long &c, const long &ivalue, const float &fvalue, const double &dvalue)
{
	if (c > 254 || c < 0)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (ivalue < std::numeric_limits<int>::min() || ivalue > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << ivalue << std::endl;
	if (fvalue - (int)fvalue == 0.0)
		std::cout << "float: " << fvalue << ".0f" << std::endl;
	else
		std::cout << "float: " << fvalue << "f" << std::endl;
	if (dvalue - (int)dvalue == 0.0)
		std::cout << "double: " << dvalue << ".0" << std::endl;
	else
		std::cout << "double: " << dvalue << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	long	c = 0;
	long	ivalue = 0;
	float	fvalue = 0.0f;
	double	dvalue = 0.0;
	
	if (str == "-inff")
    {
        float fvalue = -std::numeric_limits<float>::infinity();
		cast(str, fvalue, ivalue, dvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
	}
    else if (str == "+inff")
    {
        float fvalue = std::numeric_limits<float>::infinity();
		cast(str, fvalue, ivalue, dvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (str == "nanf")
    {
        float fvalue = std::numeric_limits<float>::quiet_NaN();
		cast(str, fvalue, ivalue, dvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (str == "-inf")
    {
        double dvalue = -std::numeric_limits<double>::infinity();
		cast(str, dvalue, ivalue, fvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (str == "+inf")
    {
        double dvalue = std::numeric_limits<double>::infinity();
		cast(str, dvalue, ivalue, fvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (str == "nan")
    {
        double dvalue = std::numeric_limits<double>::quiet_NaN();
		cast(str, dvalue, ivalue, fvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
	
    else if (sto<int>(str, "int"))
    {
		cast(str, ivalue, fvalue, dvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (sto<float>(str, "float"))
    {
		cast(str, fvalue, ivalue, dvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (sto<double>(str, "double"))
    {
		cast(str, dvalue, ivalue, fvalue, c);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else if (sto<char>(str, "char"))
    {
		cast(str, c, ivalue, fvalue, dvalue);
		print_value(c, ivalue, fvalue, dvalue);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}