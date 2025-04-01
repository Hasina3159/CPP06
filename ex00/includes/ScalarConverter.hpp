/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:40:52 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/04/01 16:06:02 by ntodisoa         ###   ########.fr       */
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


template <typename T>
T stringTo(const std::string &str)
{
	T value;
	std::stringstream ss(str);
	ss >> value;
	return (value);
}


template <typename T1, typename T2, typename T3, typename T4>
inline void cast(const std::string &str, T1 &v1, T2 &v2, T3 &v3, T4 &v4)
{
	if (static_cast<int>(v1) == 0)
		v1 = stringTo<T1>(str);
	v2 = static_cast<T2>(v1);
	v3 = static_cast<T3>(v1);
	v4 = static_cast<T4>(v1);
}
