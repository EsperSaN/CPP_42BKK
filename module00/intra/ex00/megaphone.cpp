/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:38:21 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/15 14:37:23 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// the static_cast<type> use in cpp to cast and show the error on the compile 
//but c style cast (type) not show the error (just warning)

int main(int ac, char **av)
{
	if (ac < 2)
		return ((std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::flush), 1);
	for (int i = 1; i < ac; i++)
		for (char *str = av[i]; *str; str++)
			if (*str >= 'a' && *str <= 'z')
				std::cout << static_cast<char>(((*str) - 32)) << std::flush;
			else
				std::cout << *str << std::flush;
	std::cout << std::endl;
}

// In summary, using std::endl in C++ will flush the output buffer and write the data to the output device immediately, 
// while using \n will not flush the output buffer until it is necessary or manually triggered.
// << std::endl same to std::cout << ‘\n’ << flush; 
