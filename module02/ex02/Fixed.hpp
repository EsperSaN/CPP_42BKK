/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:06 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/08 09:09:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public :
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int integer);
		Fixed(const float floatingPoint);

		//getters and setters		
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		//operators
		Fixed 	&operator=(const Fixed &rightSide);
		// arimatric operators
		Fixed 	operator+(const Fixed &rightSide) const;
		Fixed 	operator-(const Fixed &rightSide) const;
		Fixed 	operator*(const Fixed &rightSide) const;
		Fixed 	operator/(const Fixed &rightSide) const;
		
		Fixed 	operator++(void);
		//pre (void)
		Fixed 	operator++(int);
		//post (int)
		Fixed 	operator--(void);
		
		Fixed 	operator--(int);

		//compare
		//https://en.cppreference.com/w/cpp/language/operator_arithmetic
		bool 	operator>(const Fixed &rightSide) const;
		bool 	operator<(const Fixed &rightSide) const;
		bool 	operator>=(const Fixed &rightSide) const;
		bool 	operator<=(const Fixed &rightSide) const;
		bool 	operator==(const Fixed &rightSide) const;
		bool 	operator!=(const Fixed &rightSide) const;
		
		//max min

		static Fixed& max(const Fixed &a, const Fixed &b);
		static Fixed& min(const Fixed &a, const Fixed &b);
		
		
		//converters
		float 	toFloat(void) const;
		int 	toInt(void) const;
	private :
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif