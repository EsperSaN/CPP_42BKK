/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyUtil.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:17:56 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/16 20:45:12 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYUTIL_HPP
#define MYUTIL_HPP

#include <stdio.h>

#include <iomanip>
#include <iostream>

namespace MyUtil {
std::string stringTrim(std::string str);
std::string getLineAndTrim(std::string prompt);
void clearEofBit();
bool isAllDigit(std::string str);
}  // namespace MyUtil

#endif
