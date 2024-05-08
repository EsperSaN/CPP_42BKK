/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:41:09 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/07 22:32:56 by pruenrua         ###   ########.fr       */
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
	std::cout << DEFAULT << " void" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::~Fixed(void)
{
	std::cout << DESTRUCTOR << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << DEFAULT << " INT"<< std::endl;
	this->_fixedPointValue = (integer << FRACTIONAL_BITS);
}

Fixed::Fixed(const float floatingPoint)
{
	std::cout << DEFAULT << " Float"<< std::endl;
	float result;
	
	this->_fixedPointValue = roundf((floatingPoint * 1.0) << FRACTIONAL_BITS);
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
	result = (this->getRawBits()) + (this->getRawBits FRACTIONAL_BITS);
	return (result);
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> FRACTIONAL_BITS);
}

Fixed Fixed::operator+(const Fixed &rightSide) const
{
	Fixed	result;
	int		rawBits;
	
	rawBits = this->_fixedPointValue + rightSide.getRawBits();
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator-(const Fixed &rightSide) const
{
	Fixed	result;
	int		rawBits;
	
	rawBits = this->_fixedPointValue - rightSide.getRawBits();
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator*(const Fixed &rightSide) const
{
	Fixed	result;
	int		rawBits;
	
	rawBits = (this->_fixedPointValue * rightSide.getRawBits());
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &rightSide) const
{
	Fixed	result;
	int		rawBits;
	
	rawBits = (this->_fixedPointValue / rightSide.getRawBits());
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator++(void)
{
	Fixed result;
	int rawBits;
	
	rawBits = this->_fixedPointValue + 1;
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator++(int)
{
	Fixed result;
	int rawBits;
	
	rawBits = this->_fixedPointValue;
	result.setRawBits(rawBits);
	this->_fixedPointValue++;
	return (result);
}

Fixed Fixed::operator--(void)
{
	Fixed result;
	int rawBits;
	
	rawBits = this->_fixedPointValue - 1;
	result.setRawBits(rawBits);
	return (result);
}

Fixed Fixed::operator--(int)
{
	Fixed result;
	int rawBits;
	
	rawBits = this->_fixedPointValue;
	result.setRawBits(rawBits);
	this->_fixedPointValue--;
	return (result);
}

bool Fixed::operator>(const Fixed &rightSide) const
{
	return (this->_fixedPointValue > rightSide.getRawBits());
}

bool Fixed::operator<(const Fixed &rightSide) const
{
	return (this->_fixedPointValue < rightSide.getRawBits());
}

bool Fixed::operator>=(const Fixed &rightSide) const
{
	return (this->_fixedPointValue >= rightSide.getRawBits());
}

bool Fixed::operator<=(const Fixed &rightSide) const
{
	return (this->_fixedPointValue <= rightSide.getRawBits());
}

bool Fixed::operator==(const Fixed &rightSide) const
{
	return (this->_fixedPointValue == rightSide.getRawBits());
}

bool Fixed::operator!=(const Fixed &rightSide) const
{
	return (this->_fixedPointValue != rightSide.getRawBits());
}

//https://stackoverflow.com/questions/7311041/const-to-non-const-conversion-in-c
Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (const_cast<Fixed&>(a));
	return const_cast<Fixed&>(b);
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (const_cast<Fixed&>(a));
	return const_cast<Fixed&>(b);
}

