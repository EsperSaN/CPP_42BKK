/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:41:09 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/09 16:34:06 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
//https://stackoverflow.com/questions/476272/how-can-i-properly-overload-the-operator-for-an-ostream
//global function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat() << std::flush;
	return (out);
}

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

Fixed::Fixed(const int integer)
{
	std::cout << "INT : " <<  DEFAULT << std::endl;
	this->_fixedPointValue = (integer * (1 << FRACTIONAL_BITS));
}

Fixed::Fixed(const float floatingPoint)
{
	std::cout << "Float : " << DEFAULT << std::endl;
	this->_fixedPointValue = roundf(floatingPoint * (1 << FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << COPY << std::endl;
	this->operator=(src);
	//*this = src;
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
	result = (static_cast<float>(this->_fixedPointValue)) / (1 << FRACTIONAL_BITS);
	return (result);
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> FRACTIONAL_BITS);
}
