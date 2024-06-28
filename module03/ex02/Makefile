# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 21:05:54 by pruenrua          #+#    #+#              #
#    Updated: 2024/06/27 19:10:58 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap	

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MP -MMD

CPP_FILE = Claptrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

HPP_FILE = Claptrap.hpp ScavTrap.hpp FragTrap.hpp

OBJ = $(CPP_FILE:.cpp=.o)

DEPS = $(OBJ:.o=.d)

# %.o: %.cpp $(HPP_FILE)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) $(DEPS)

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all clean fclean re 