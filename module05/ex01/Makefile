# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 21:05:54 by pruenrua          #+#    #+#              #
#    Updated: 2024/07/04 19:29:20 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP

CPP_FILE =  Bureaucrat.cpp Form.cpp main.cpp

# HPP_FILE =  Bureaucrat.h

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