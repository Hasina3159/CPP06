/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:40:54 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 15:37:31 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <typeinfo>

void ScalarConverter::convert(const std::string &str)
{
	/*
	float	f;
	double	d;
	int		i;
	char	c;
	unsigned int	idx;
	*/

	if (sto<int>(str, "int"))
		std::cout << std::string(typeid(5).name()) << std::endl;
	else if (sto<float>(str, "float"))
		std::cout << std::string(typeid(5.0f).name()) << std::endl;
	else if (sto<double>(str, "double"))
		std::cout << std::string(typeid(5.0).name()) << std::endl;
	else if (sto<char>(str, "char"))
		std::cout << std::string(typeid('c').name()) << std::endl;
	else
		std::cout << "Impossible" <<  std::endl;

}