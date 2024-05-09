/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:06 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/09 12:54:09 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define FRACTIONAL_BITS 8
#define DEFAULT "Default constructor called"
#define DESTRUCTOR "Destructor called"
#define COPY "Copy constructor called"
#define ASSIGN "Copy assignment operator calle"
#define GET "getRawBits member function called"
#define SET "setRawBits member function called"

class Fixed {
	public :
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rightSide);
		//othordox things
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		//getters and setters		
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

		//converters
		float 	toFloat(void) const;
		int 	toInt(void) const;
	private :
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
