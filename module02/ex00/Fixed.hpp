/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:06 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/06 07:22:12 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
	public :
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rightSide);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private :
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;
};
