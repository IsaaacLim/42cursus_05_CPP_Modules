NAME		=	phonebook

SRCS		=	ClassContacts.cpp	contacts.cpp	ft_add.cpp	ft_search.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp ClassContacts.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
