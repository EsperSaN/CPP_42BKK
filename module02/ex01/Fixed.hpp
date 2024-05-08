/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:06 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/08 09:08:49 by pruenrua         ###   ########.fr       */
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
		
		Fixed &operator=(const Fixed &rightSide);
		//std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
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