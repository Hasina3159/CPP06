/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:40:52 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 15:34:45 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
public:
	static void convert(const std::string &str);
};

template <typename T>
bool sto(const std::string &str, const std::string &type)
{
	T 					value;
	std::stringstream	ss;
	std::stringstream	ss2;
	std::string			out;
	
	ss << str;
	ss >> value;

	ss2 << value;
	out = ss2.str();
	
	if ((value - (int)value) == 0.0)
		out = out + ".0";
		
	if (type == "float")
	{
		if (std::string(out + "f") == str)
			return (true);
		else
			return (false);
	}
	
	if (type == "char")
	{
		if (str.length() == 1 && isprint(str[0]))
			return (true);
		return (false);
	}
		
	if (ss.fail() || !ss.eof())
		return (false);
		
	return (true);	

}

/*template <typename T>

T print(const std::string &str, const std::string &type)
{
	T var;

	std::cout << type << ": " << std::flush;
	
	try
	{
		if (type == "char")
			var = sto<unsigned int>(str);
		else
			var = sto<T>(str);
		
		std::cout << var << std::flush;

		if ((type == "float" || type == "double") && (var - static_cast<int>(var)) == 0.0)
			std::cout << ".0" << std::flush;
		if (type == "float")
			std::cout << "f" << std::flush;
		std::cout << std::endl;
	}
	catch(...)
	{
		std::cout << "impossible" << std::endl;
	}
	return (var);
}*/