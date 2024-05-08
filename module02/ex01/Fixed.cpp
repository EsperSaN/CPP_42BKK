/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:41:09 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/07 22:27:24 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#define FRACTIONAL_BITS 8
#define DEFAULT "Default constructor called"
#define DESTRUCTOR "Destructor called"
#define COPY "Copy constructor called"
#define ASSIGN "Copy assignment operator calle"
#define GET "getRawBits member function called"
#define SET "setRawBits member function called"
//https://stackoverflow.com/questions/476272/how-can-i-properly-overload-the-operator-for-an-ostream
//global function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::Fixed(void)
{
	std::cout << DEFAULT << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::~Fixed(void)
{
	std::cout << DESTRUCTOR << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << DEFAULT << std::endl;
	this->_fixedPointValue = (integer << FRACTIONAL_BITS);
}

Fixed::Fixed(const float floatingPoint)
{
	std::cout << DEFAULT << std::endl;
	this->_fixedPointValue = roundf(floatingPoint * (1 << FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << COPY << std::endl;
	this->_fixedPointValue = src.getRawBits();
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

float Fixed::toFloat(void) const
{
	float result;
	result = static_cast<float>(this->_fixedPointValue) / (1 << FRACTIONAL_BITS);
	return (result);
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> FRACTIONAL_BITS);
}

