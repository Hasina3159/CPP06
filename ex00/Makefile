NAME = bureaucrat

CXX = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = $(shell find . -name "*.cpp" | tr '\n' ' ')

OBJS = $(SRCS:.cpp=.o)

$%.o		:	%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CXX) $(CPPFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

clean		:
	rm -rf $(OBJS)

fclean		:	clean
	rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
