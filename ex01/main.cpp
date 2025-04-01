/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:57:04 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/04/01 16:37:42 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

void testSerialization()
{
    Data originalData;
    originalData.i = 42;
    originalData.j = 101010;

    uintptr_t raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    assert(deserializedData == &originalData);
    assert(deserializedData->i == originalData.i);
    assert(deserializedData->j == originalData.j);

    std::cout << "testSerialization passed!" << std::endl;
}

void testInvalidDeserialization()
{
    uintptr_t invalidRaw = 0;
    Data* deserializedData = Serializer::deserialize(invalidRaw);

    assert(deserializedData == NULL);

    std::cout << "testInvalidDeserialization passed!" << std::endl;
}

int main(void)
{
    testSerialization();
    testInvalidDeserialization();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
