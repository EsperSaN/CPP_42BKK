/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:41:09 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/09 12:29:10 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << DEFAULT << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::~Fixed(void)
{
	this->_fixedPointValue = 0;
	std::cout << DESTRUCTOR << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << COPY << std::endl;
	this->operator=(src);
	// this->_fixedPointValue = src.getRawBits();
}

//https://www.geeksforgeeks.org/assignment-operator-overloading-in-c/

Fixed &Fixed::operator=(const Fixed &rightSide)
{
	std::cout << ASSIGN << std::endl;
	if (this != &rightSide)
		this->_fixedPointValue = rightSide.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << GET << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << SET << std::endl;
	this->_fixedPointValue = raw;
}
